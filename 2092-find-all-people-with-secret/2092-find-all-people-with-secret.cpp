class UnionFind {
    vector<int> par;
    public:
    UnionFind(int n) {
        par.resize(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    
    void connect(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        par[parA] = parB;
    }
    
    int find(int a) {
        if (par[a] == a)
            return a;
        
        return par[a] = find(par[a]);
    }
    
    bool isConnected(int a, int b) {
        int para = find(a);
        int parb = find(b);
        return para == parb;   
    }
    
    void reset(int a) {
        par[a] = a;
    }
    
};

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>> meetingsMap;
        
        for (auto vec : meetings) {
            int x = vec[0];
            int y = vec[1];
            int time = vec[2];
            meetingsMap[time].push_back({x, y});
        }
        
        UnionFind* uf = new UnionFind(n);
        
        uf -> connect(firstPerson, 0);
        
        set<int> people;
        for (auto [time, meetingArray] : meetingsMap) {
            
            people.clear();
            for (auto [person1, person2] : meetingArray) {
                uf -> connect(person1, person2);
                people.insert(person1);
                people.insert(person2);
            }
            
            for (int person : people) {
                if (!uf -> isConnected(person, 0))
                    uf -> reset(person);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (uf -> isConnected(i, 0))
                res.push_back(i);
        }
        
        return res;
        
    }
};