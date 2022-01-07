class Solution {
public:
    const int ENTER = 0;
    const int LEAVE = 1;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> vec;
        int n = trips.size();
        for (int i = 0; i < n; i++) {
            int nPassengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            vec.push_back({from, nPassengers});
            vec.push_back({to, -1 * nPassengers});
        }
        
        sort(vec.begin(), vec.end());
        
        int currCapacity = 0;
        for (int i = 0; i < vec.size(); i++) {
            currCapacity += vec[i].second;
            if(currCapacity > capacity)
                return false;
        }
        
        return true;
    }
};