class Solution {
public:    
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> Q;
        unordered_set<string> locks;
        unordered_map<string, bool> vis;
        
        for(int i = 0; i < deadends.size(); i++) {
            locks.insert(deadends[i]);
        }
        
        Q.push({"0000", 0});
        vis["0000"] = true;
        
        if (locks.find("0000") != locks.end())
            return -1;
        
        
        while (!Q.empty()) {
            string currCombination = Q.front().first;
            int moves = Q.front().second;
            Q.pop();
            
            if (currCombination == target)
                return moves;
            
            for (int i = 0; i < 4; i++) {
                string combination1 = currCombination;
                string combination2 = currCombination;
                
                combination1[i] = (char)((combination1[i] -'0' + 1 + 10) % 10 + '0');
                combination2[i] = (char)((combination2[i] -'0' - 1 + 10) % 10 + '0');
                
                if(locks.find(combination1) == locks.end() && !vis[combination1]) {
                    Q.push({combination1, moves + 1});
                    vis[combination1] = true;
                }
                if(locks.find(combination2) == locks.end() && !vis[combination2]) {
                    Q.push({combination2, moves + 1});
                    vis[combination2] = true;
                }
            }
        }
        
        return -1;
    }
};