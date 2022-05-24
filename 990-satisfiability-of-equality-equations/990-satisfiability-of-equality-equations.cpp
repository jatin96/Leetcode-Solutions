class UnionFind {
    vector<int> par;
public:
    UnionFind() {
        for (int i = 0; i < 26; i++)
            par.push_back(i);
    }
    
    void connect(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        par[parA] = parB;
    }
    
    int find(int a) {
        if (a == par[a]) return a;
        return par[a] = find(par[a]);
    }
    
    bool isConnected(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        return parA == parB;
    }
};



class Solution {
public:
    
    unordered_set<int> findVariables(vector<string> & equations) {
        
        unordered_set<int> vars;
        for (string equation : equations) {
            int a = equation[0] - 'a';
            int b = equation[3] - 'a';
            vars.insert(a);
            vars.insert(b);
        }
        
        return vars;
    }
    
    bool equationsPossible(vector<string>& equations) {
        unordered_set<int> vars = findVariables(equations);
        UnionFind* uf = new UnionFind();
        
        for (string equation : equations) {
            int var1 = equation[0] - 'a';
            cout << equation << endl;
            string operation = "";
            operation.push_back(equation[1]); operation.push_back(equation[2]);
            int var2 = equation[3] - 'a';
            
            if (operation == "==") {
                uf -> connect(var1, var2);
            } 
        }
        
        for (string equation : equations) {
            int var1 = equation[0] - 'a';
            cout << equation << endl;
            string operation = "";
            operation.push_back(equation[1]); operation.push_back(equation[2]);
            int var2 = equation[3] - 'a';
            
            if (operation == "!=") {
                if (uf -> isConnected(var1, var2))
                    return false;
            } 
        }
        
        return true;
    }
};