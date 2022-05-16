class Solution {
public:
    vector<vector<int>> dp, matrix;
    int n, m;
    int N = 4;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isValid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int solveIt(int x, int y) {
        
        if (dp[x][y] != -1) return dp[x][y];
        
        int res = 1;
        for (int i = 0; i < N; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
           
            if (isValid(x1, y1) && matrix[x1][y1] > matrix[x][y])
                res = max(res, 1 + solveIt(x1, y1));
        }
        
        return dp[x][y] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        this -> matrix = matrix;
        
        dp.resize(n, vector<int> (m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = -1;
        
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    res = max(res, solveIt(i, j));
            }
        }
        
        return res;
        
    }
};