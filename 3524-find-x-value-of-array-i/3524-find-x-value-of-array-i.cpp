class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);
            int v = num % k;

            ndp[v]++;

            for (int r = 0; r < k; r++)  {
                int nr = ( r * v) % k;
                ndp[nr] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
        
        
    }
};