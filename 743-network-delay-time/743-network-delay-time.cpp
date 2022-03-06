class Solution {
public:
    const int INF = 100000000;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INF);
        
        dist[k] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto &time : times) {
                int u = time[0];
                int v = time[1];
                int w = time[2];
                
                if (dist[u] != INF)
                    dist[v] = min(dist[v], dist[u] + w);
            }
        }
        
        int res = -1;
        for (int i = 1; i <= n; i++) {
            res = max(res, dist[i]);
        }
        
        return (res == INF ? -1 : res);
    }
};