class Solution {
public:
    long long INF = (long long)1e12;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<long long>> dist(n, vector<long long>(m, INF));
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            long long weight = pq.top()[0];
            long long x = pq.top()[1];
            long long y = pq.top()[2];
            pq.pop();
            
            if (x == n - 1 && y == m - 1) return (int)dist[x][y];
            
            if (dist[x][y] < weight) continue;
            
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (isValid(x1, y1, n, m) && dist[x1][y1] > max(weight, abs((long long)heights[x1][y1] - heights[x][y]))) {
                    dist[x1][y1] = max(weight, abs((long long)heights[x1][y1] - heights[x][y]));
                    pq.push({dist[x1][y1], x1, y1});
                }
            }
        }
        
        return 0;
    }
};