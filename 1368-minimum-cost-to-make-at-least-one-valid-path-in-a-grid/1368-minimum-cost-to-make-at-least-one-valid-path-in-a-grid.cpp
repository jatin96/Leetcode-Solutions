class Solution {
public:
    typedef pair<int, pair<int, int>> pii;
    
    int dir[5][2] = {{0,0}, {0,1}, {0, -1}, {1, 0}, {-1, 0}};
    int N_dir = 4;
    int INF = 100000007;
    
    int n, m;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        bool mark[107][107] = {false};
        
        priority_queue < pii, vector<pii>, greater<pii>> Q;
        
        int dist[107][107];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                dist[i][j] = INF;
            
        
        Q.push({0, {0, 0}});
        dist[0][0] = 0;
        
        mark[0][0] = true;
        
        while(!Q.empty()) {
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            int cost = Q.top().first;
                    
            Q.pop();
            
            if (dist[x][y] < cost) continue;
           
            for (int i = 1; i <= N_dir; i++) {
                int x1 = x + dir[i][0];
                int y1 = y + dir[i][1];
                
                if(!isValid(x1, y1)) continue;
                
                int edge_wt = ((i == grid[x][y]) ? 0 : 1);
                
                if(dist[x][y] + edge_wt < dist[x1][y1]) {
                    dist[x1][y1] = dist[x][y] + edge_wt;
                    Q.push({dist[x1][y1], {x1, y1}});
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};