class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m =grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2) return false;
        if (grid[0][0] ==')' || grid[m-1][n-1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n + 1, false)));

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    continue;

                for (int bal = 0; bal <= m+n; bal++) {

                    int nb = bal + (grid[i][j] == '(' ? 1 : -1);
                    if (nb < 0 || nb > m+n) continue;

                    if (i > 0 && dp[i-1][j][bal])
                        dp[i][j][nb] = true;

                    if (j > 0 && dp[i][j-1][bal])
                        dp[i][j][nb] = true;
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};