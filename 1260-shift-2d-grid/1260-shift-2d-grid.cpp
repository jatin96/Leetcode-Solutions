class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> arr(n * m, 0);
        
        vector<vector<int>> newGrid(n, vector<int> (m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[(m * i + j + k) % (n * m)] = grid[i][j];
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                newGrid[i][j] = arr[i * m + j];
        
        return newGrid;
    }
};