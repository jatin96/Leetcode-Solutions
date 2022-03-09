class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }
    
    int find(int x, int *par) {
        if (x == par[x])
            return x;
        
        return par[x] = find(par[x], par);
    }
    
    bool union1(int a, int b, int *par, int &distinct) {
        int parA = find(a, par);
        int parB = find(b, par);
        if (parA == parB) {
            return true;
        } else { 
            par[parA] = parB;
            distinct--;
            return false;
        }
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int parAlice[n + 1];
        int parBob[n + 1];
        
        sort(edges.begin(), edges.end(), cmp);
        
        for (int i = 0; i <= n; i++) {
            parAlice[i] = i;
            parBob[i] = i;
        }
        
        
        int edgeCnt = 0, aliceCnt = n, bobCnt = n;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][2];
            int type = edges[i][0];
            
            if (type == 3) {
                bool isComponentSameA = union1(u, v, parAlice, aliceCnt);
                bool isComponentSameB = union1(u, v, parBob, bobCnt);
                if (!(isComponentSameA && isComponentSameB))
                    edgeCnt++;
                    
            } 
            else if (type == 2) {
                bool isComponentSameB = union1(u, v, parBob, bobCnt);
                if (!isComponentSameB)
                    edgeCnt++;
            } 
            else {
                bool isComponentSameA = union1(u, v, parAlice, aliceCnt);
                if(!isComponentSameA)
                    edgeCnt++;
            }
        }
        
        if (aliceCnt != 1 || bobCnt != 1) return -1;
        
        return edges.size() - edgeCnt;        
        
    }
};