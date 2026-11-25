class Solution {
public:
    static const long long MOD1 = 1000000007;
    static const long long MOD2 = 1000000009;
    static const long long BASE1 = 131;
    static const long long BASE2 = 137;

    bool check(vector<int>& nums, int len) {
        int n = nums.size();

        unordered_map<long long, int> mp;

        long long h1 = 0, h2 = 0;
        long long p1 = 1, p2 = 1;

        // Calculate BASE^len
        for (int i = 0; i < len; i++) {
            p1 = (p1 * BASE1) % MOD1;
            p2 = (p2 * BASE2) % MOD2;
        }

        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE1 + nums[i]) % MOD1;
            h2 = (h2 * BASE2 + nums[i]) % MOD2;
        }

        mp[(h1 << 32) | h2]++;

        for (int i = len; i < n; i++) {
            h1 = (h1 * BASE1 + nums[i]
                  - p1 * nums[i - len] % MOD1 + MOD1) % MOD1;

            h2 = (h2 * BASE2 + nums[i]
                  - p2 * nums[i - len] % MOD2 + MOD2) % MOD2;

            mp[(h1 << 32) | h2]++;
        }

        for (auto& [hash, freq] : mp) {
            if (freq == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};