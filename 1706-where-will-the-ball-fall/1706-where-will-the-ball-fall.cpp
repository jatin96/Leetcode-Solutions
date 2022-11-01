class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    
    bool isBallStuck(int x, int y) {
        if(y == 0 && grid[x][y] == -1)
            return true;
        
        if(y == m - 1 && grid[x][y] == 1)
            return true;
        
        if(grid[x][y] == 1 && grid[x][y + 1] == -1)
            return true;
        
        if(grid[x][y] == -1 && grid[x][y - 1] == 1)
            return true;
        
        return false;
    }
    
    int findEscapeColumn(int depth, int col) {
        if (depth == n)
            return col;
        
        if(isBallStuck(depth, col))
            return -1;
        
        return findEscapeColumn(depth + 1, col + grid[depth][col]);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        this -> grid = grid;
        n = grid.size();
        m = grid[0].size();
        
        vector<int> res;
        
        for (int i = 0; i < m; i++) {
            res.push_back(findEscapeColumn(0, i));
        }
        
        return res;
    }
};