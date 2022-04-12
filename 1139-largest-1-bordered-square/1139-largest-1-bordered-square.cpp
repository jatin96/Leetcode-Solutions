class Solution {
public:
    vector<vector<int>> grid;
    bool isSquareValid(int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++)
            if(grid[i][y1] == 0 || grid[i][y2] == 0) return false;
        
        for (int i = y1; i <= y2; i++)
            if(grid[x1][i] == 0 || grid[x2][i] == 0) return false;
        
        return true;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        this -> grid = grid;
        
        for (int size = min(n, m); size >= 0; size--) {
            for (int i = size - 1; i < n; i++) {
                for (int j = size - 1; j < m; j++) {
                    if (isSquareValid(i - size + 1, j - size + 1, i, j)) return size * size;
                }
            }
        }
        
        return 0;   
    }
};