class Solution {
public:
    static const int N = 100005;
    long long INF = 10000000000000;
    int E, n;
    vector<pair<int, int>> G[N], T[N];
    
    vector<long long> dijkstra(vector<pair<int, int>> *G, int src) {
        
        vector<long long> dist(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater< pair<long long, int> > > Q;
        
        Q.push({0, src});
        dist[src] = 0;
        
        while (!Q.empty()) {
            int u = Q.top().second;
            long long cost = Q.top().first;
            Q.pop();
            
            if (dist[u] < cost)
                continue;
            
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].first;
                int w = G[u][i].second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        E = edges.size();
        this -> n = n;
        vector<long long> dist1(N, INF), dist2(N, INF), dist3(N, INF);
        
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            G[u].push_back({v, w});
            T[v].push_back({u, w});
        }
        
        dist1 = dijkstra(G, src1);
        dist2 = dijkstra(G, src2);
        dist3 = dijkstra(T, dest);
        
        long long res = INF;
        for (int i = 0; i < n; i++) {
            long long cost = dist1[i] + dist2[i] + dist3[i];
            res = min(res, cost);
        }
        
        if (res >= INF) return -1;
        return res;
        
    }
};