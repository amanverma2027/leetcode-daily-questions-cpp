class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;
            int prevMax = 0;

            for (int start = 0; start < n &&  valid; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                for (int j =start; j < start + k; j++) {
                    int next = (j + 1 == start + k)
                        ? start : j + 1;

                    if (nums[j] > nums[next]) {
                        descents++;
                    }

                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};