class Solution {
public:
    vector<int> g[1000007];
    bool vis[1000007];
    int res = 1;
    string s;
    int dfs(int u) {
        vis[u] = true;
        
        priority_queue<int> pq;
        int big1 = 0, big2 = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!vis[v]) {
                int curr = dfs(v);
                if (s[v] == s[u]) continue;
                if (curr > big2) big2 = curr;
                if (big2 > big1) swap(big1, big2);
            }
        }
        
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        this -> s = s;
        memset(vis, false, sizeof vis);
        for (int i = 1; i < parent.size(); i++) {
            if (parent[i] < 0)
                continue;
            g[parent[i]].push_back(i);
        }
        
        dfs(0);
        return res;
    }
};