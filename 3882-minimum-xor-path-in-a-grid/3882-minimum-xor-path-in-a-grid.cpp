class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mx = 0;
        for (auto& row : grid) {
            for (int x : row) {
                mx = max(mx, x);
            }
        }

        int K = 1;
        while (K <= mx) K *= 2;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(K, false)));

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int x = grid[i][j];

                for (int k = 0; k < K; k++) {
                    int prev = k ^ x;

                    if (i > 0 && dp[i - 1][j][prev]) {
                        dp[i][j][k] = true;
                    }

                    if (j > 0 && dp[i][j - 1][prev]) {
                        dp[i][j][k] = true;
                    }
                }
            }
        }

        for (int k = 0; k < K; k++) {
            if (dp[m - 1][n - 1][k]) {
                return k;
            }
        }

        return 0;
    }
};