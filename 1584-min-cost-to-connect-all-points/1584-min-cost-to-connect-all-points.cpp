class Solution {
public:
    vector<pair<int , pair<int, int>>> edges;
    int n;
    vector<int> parent;
    vector<int> rank;
    
    int getDist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    void unionNodes(int parentU, int parentV) {
        if (rank[parentU] <= rank[parentV]) {
            parent[parentU] = parentV;
            rank[parentV] += rank[parentU];
        } else {
            parent[parentV] = parentU;
            rank[parentU] += rank[parentV];
        }
    }
    
    int findParent(int u) {
        if (u == parent[u]) return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        
        parent.resize(n);
        rank.resize(n);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.push_back({getDist(points[i][0], points[i][1], points[j][0], points[j][1]), {i, j}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int cost = 0;
        for (auto edge : edges) {
            int weight = edge.first;
            int nodeU = edge.second.first;
            int nodeV = edge.second.second;
            
            int parentU = findParent(nodeU);
            int parentV = findParent(nodeV);
            
            if (parentU != parentV) {
                unionNodes(parentU, parentV);
                cost += weight;
            }
        }
        
        return cost;
    }
};