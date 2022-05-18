class Solution {
public:
    typedef pair<int, int> pi;
    int INF = 10000007;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<pi> graph[107];
        vector<bool> vis(n, false);
        
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            graph[u].push_back({v, w});
        }
        
        int dist[107];
        
        for (int i = 0; i <= n; i++)
            dist[i] = INF;
        
        
        pq.push({0, k});
        dist[k] = 0;
        
        while (!pq.empty()) {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (vis[node]) continue;
            
            for (auto [child, w] : graph[node]) {
                if (vis[child] == false && dist[node] + w < dist[child]) {
                    dist[child] = dist[node] + w;
                    pq.push({dist[child], child});
                }
            }
            
            vis[node] = true;
        }
        
        int maxi = -1;
        for (int i = 1; i <= n; i++) {
            maxi = max(maxi, dist[i]);
        }
        
        return maxi >= INF ? -1 :maxi;
    }
};