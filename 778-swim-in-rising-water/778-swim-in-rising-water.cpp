class Solution {
private:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool valid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    bool possible(int x, int y, int n, int cost, vector<vector<int>>& grid, vector<vector<bool>>& used) {
        if(x == n-1 && y == n-1) {
            return true;
        }
        
        if(grid[x][y] > cost)
            return false;
        
        used[x][y] = true;
        bool flag = false;
        for(int i = 0; i < 4; i++) {
            int a = x + dir[i][0];
            int b = y + dir[i][1];
            if(valid(a, b, n) && !used[a][b] && grid[a][b] <= cost)
                if (possible(a, b, n, cost, grid, used))
                    return true;
        }
        
        return false;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = -1;
        int n  = grid.size();
        
        vector<vector<bool>> used(n, vector<bool>(n, false));
        
        
        int low = 0, high = n*n; 
        while(low <= high) {
            int mid = (low + high) / 2;
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++)
                    used[i][j] = false;
            }
            
            if(possible(0, 0, n, mid, grid, used)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        
        return ans;
    }
};