class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<pair <int, int>> Q;
        
        unordered_map<int, vector<int>> posMap;
        int n = arr.size();
        
        for (int i = 0;i < n; i++)
            posMap[arr[i]].push_back(i);
    
        bool vis[50007] = {false};
        
        Q.push({0,0});
        vis[0] = true;
        
        while (!Q.empty()) {
            
            auto [nodeIdx, steps] = Q.front();
            Q.pop();
            
            if (nodeIdx == n - 1) return steps;
            
            if (nodeIdx + 1 < n && vis[nodeIdx + 1] == false) {
                vis[nodeIdx + 1] = true;
                Q.push({nodeIdx + 1, steps + 1});
            }
            
            if(nodeIdx - 1 >= 0 && vis[nodeIdx - 1] == false) {
                vis[nodeIdx - 1] = true;
                Q.push({nodeIdx - 1, steps + 1});
            }
            
            
            for (auto nextNode : posMap[arr[nodeIdx]]) {
                if (vis[nextNode] == false) {
                    vis[nextNode] = true;
                    Q.push({nextNode, steps + 1});
                }
            }
            
            posMap.erase(arr[nodeIdx]);
        }
        
        return -1;
    }
};