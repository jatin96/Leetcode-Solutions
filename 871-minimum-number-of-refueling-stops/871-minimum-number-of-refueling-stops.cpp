class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        
        int currDist = startFuel, idx = 0, res = 0;
        while (currDist < target) {
            while (idx < stations.size() && stations[idx][0] <= currDist)
                pq.push(stations[idx++][1]);
            
            if (pq.empty()) return -1;
            
            currDist += pq.top();
            pq.pop();
            res++;
        }
        
        return res;
    }
};