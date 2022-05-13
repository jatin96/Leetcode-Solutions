class Solution {
public:
    vector<int> graph[100007];
    vector<int> manager;
    vector<int> informTime;
    int headID, n;
    void initialize() {
        for (int i = 0; i < manager.size(); i++) 
            if (manager[i] != -1) 
                graph[manager[i]].push_back(i);
    }
    
    int dfs(int x) {
        
        int res = 0;
        for (int child : graph[x]) {
            res = max(res, informTime[x] + dfs(child));
        }
        
        return res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        this -> n = n;
        this -> headID = headID;
        this -> manager = manager;
        this -> informTime = informTime;
        initialize();
        return dfs(headID);
    }
};