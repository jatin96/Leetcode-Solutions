class Solution {
public:
    bool isValid(long long pos, long long speed, long long target) {
        if (pos == target) return true;
        
        if (speed < 0 && target < pos) return true;
        
        if (speed > 0 && target > pos) return true;
        
        return false;
    }
    
    int racecar(int target) {
        queue<pair<long long, pair<long long, long long>>> Q;
        
        map<pair<long long, long long>, bool> vis;
        Q.push({0, {1, 0}});
        
        vis[{0, 1}] = true;
        while (!Q.empty()) {
            long long currPos = Q.front().first;
            long long currSpeed = Q.front().second.first;
            long long currSteps = Q.front().second.second;
            Q.pop();
            
            if (currPos == target) return (int)currSteps;
            
            if (currPos + currSpeed < (target + 1000) && 
                vis.find({currPos + currSpeed, currSpeed * 2}) == vis.end()) {
                Q.push({currPos + currSpeed, {currSpeed * 2, currSteps + 1}});
                vis[{currPos + currSpeed, currSpeed * 2}] = true;
            }
            
            if (
                currPos > - 100 && 
                vis.find({currPos, currSpeed > 0 ? -1 : 1}) == vis.end()) {
                Q.push({currPos, {currSpeed > 0 ? -1 : 1, currSteps + 1}});
                vis[{currPos, currSpeed > 0 ? -1 : 1}] = true;
            }
        }
        
        return -1;
    }
};