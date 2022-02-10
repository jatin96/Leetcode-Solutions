class Solution {
public:
    enum COLOR { White, Black, Uncolored };
    COLOR coloring[107];
    vector<vector<int>> graph;
    bool isBipartiteUtil(int node) {
        if (coloring[node] == Uncolored)
            coloring[node] = White;
        
        for (auto child : graph[node]) {
            if (coloring[child] == Uncolored) {
                coloring[child] = coloring[node] == White ? Black : White;
                if (!isBipartiteUtil(child))
                    return false;
            }
            else if (coloring[child] == coloring[node])
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        this -> graph = graph;
        for (int i = 0; i < n; i++)
            coloring[i] = Uncolored;
        
        for (int i = 0; i < n; i++) {
            if (coloring[i] == Uncolored) {
                if (!isBipartiteUtil(i))
                    return false;
            }
        }
        
        return true;
    }
};