class Solution {
public:
    bool vis[10007], dfsVis[10007];
    vector<vector<int>> G;
    int n;
    bool isCycle(int u) {
        vis[u] = true;
        dfsVis[u] = true;
        
        int m = G[u].size();
        for (int i = 0; i < m; i++) {
            int v = G[u][i];
            if(!vis[v]) {
                if(isCycle(v))
                    return true;
            }
            else if (dfsVis[v])
                return true;
        }
        
        dfsVis[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        G = graph;
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            memset(vis, false, sizeof vis);
            memset(dfsVis, false, sizeof dfsVis);
            
            if (!isCycle(i))
                res.push_back(i);
        }
        
        return res;
        
    }
};