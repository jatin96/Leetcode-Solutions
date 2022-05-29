class UnionFind {
    vector<int> parent;
public: 
    UnionFind(int n) {
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] == a) return a;
        
        return parent[a] = find(parent[a]);
    }
    
    void connect(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        
        if (parentA != parentB)
            parent[parentA] = parentB;
    }
    
    int findNoOfClusters() {
        unordered_set<int> clusters;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i)
            clusters.insert(i);
            cout << i << " parent is " << parent[i] << endl;
        }
        
        return clusters.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind* uf = new UnionFind(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                
                if (i > j && isConnected[i][j])
                    uf -> connect(i, j);
                    
            }
        }
        
        return uf -> findNoOfClusters();
    }
};