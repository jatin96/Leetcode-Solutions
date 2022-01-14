class Solution {
public:
    vector<vector<int>> vec;
    int nRows;
    int dp[300][300];
    
    bool isValid(int x, int y) {
        
        if(x >= nRows || x < 0)
            return false;
        
        if(y >= vec[x].size() || y < 0)
            return false;
        
        return true;
        
    }
    
    int minPathSum(int row, int col) {
        if (row == nRows - 1)
            return vec[row][col];
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int p = INT_MAX, q = INT_MAX;
        
        if (isValid(row + 1, col))
            p = vec[row][col] + minPathSum(row + 1, col);
        
        if(isValid(row + 1, col + 1))
            q = vec[row][col] + minPathSum(row + 1, col + 1);
        
        return dp[row][col] = min(p, q);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vec = triangle;
        nRows = triangle.size();
        memset(dp, -1, sizeof dp);
        return minPathSum(0, 0);
    }
};