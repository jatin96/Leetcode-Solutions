class Solution {
public:
    vector<vector<int>> matrix;
    int n, m;
    int dp[107][107];
    int solveIt(int row, int col) {
        if (row == n)
            return 0;
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        int below = INT_MAX, leftBelow = INT_MAX, rightBelow = INT_MAX;
        
        below = matrix[row][col] + solveIt(row + 1, col);
        
        if (col - 1 >= 0)
            leftBelow = matrix[row][col] + solveIt(row + 1, col - 1);
        
        if (col + 1 < m)
            rightBelow = matrix[row][col] + solveIt(row + 1, col + 1);
        
        return dp[row][col] = min({below, leftBelow, rightBelow});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        this -> matrix = matrix;
        memset(dp, -1, sizeof dp);
        
        int res = INT_MAX;
        for (int col = 0; col < m; col++) {
            res = min(res, solveIt(0, col));
        }
        
        return res;
    }
};