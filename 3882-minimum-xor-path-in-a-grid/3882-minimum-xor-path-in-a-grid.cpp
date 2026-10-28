class Solution {
public:
    int m, n, K = 1024;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int x, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return false;
        if (i == 0 && j == 0) return x == grid[0][0];
        if (dp[i][j][x] != -1) return dp[i][j][x];

        int prevXor = x ^ grid[i][j];
        bool ans = false;

        if (i > 0) ans |= solve(i - 1, j, prevXor, grid);
        if (j > 0) ans |= solve(i, j - 1, prevXor, grid);

        return dp[i][j][x] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

         dp.assign(m, vector<vector<int>>(n, vector<int>(K, -1)));

        for (int x = 0; x < K; x++) {
            if (solve(m - 1, n - 1, x, grid))
                return x;
        }

        return 0;
    }
};