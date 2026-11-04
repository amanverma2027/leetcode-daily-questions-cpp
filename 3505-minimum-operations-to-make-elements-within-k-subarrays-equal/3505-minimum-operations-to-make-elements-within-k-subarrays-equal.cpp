class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<long long> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long val = *it;

                left.erase(it);
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                auto it = right.begin();
                long long val = *it;

                right.erase(it);
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

            balance();
        };

        auto remove = [&](long long val) {
            auto itLeft = left.find(val);

            if (itLeft != left.end()) {
                left.erase(itLeft);
                sumLeft -= val;
            } else {
                auto itRight = right.find(val);
                right.erase(itRight);
                sumRight -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            long long leftCost =
                median * (long long)left.size() - sumLeft;

            long long rightCost =
                sumRight - median * (long long)right.size();

            return leftCost + rightCost;
        };

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        vector<long long> cost(n - x + 1);
        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }


        const long long INF = 4e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i <= n; i++) {
            for (int used = 0; used <= k; used++) {
                if (dp[used][i] == INF)
                    continue;

                if (i < n) {
                    dp[used][i + 1] =
                        min(dp[used][i + 1],
                            dp[used][i]);
                }

                if (used < k && i + x <= n) {
                    dp[used + 1][i + x] =
                        min(dp[used + 1][i + x],
                            dp[used][i] + cost[i]);
                }
            }
        }

        long long answer = INF;

        for (int i = 0; i <= n; i++) {
            answer = min(answer, dp[k][i]);
        }

        return answer;
    }
};