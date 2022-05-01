class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set <pair<int, pair <vector<int>:: iterator, int>>> ss;
        
        for (int i = 0; i < nums.size(); i++) {
            ss.insert({nums[i][0], {nums[i].begin(), i}});
        }
        
        int res = INT_MAX, low = (*ss.begin()).first, high = (*ss.rbegin()).first;
        while (true) {
            auto it = ss.begin();
            int num = (it -> first);
            auto vecIterator = (it -> second).first;
            int row = (it -> second).second;
            
            int currRange = abs((*ss.begin()).first - (*ss.rbegin()).first);
            if (currRange < res) {
                res = currRange;
                low = (*ss.begin()).first;
                high = (*ss.rbegin()).first;
            }
            
            ss.erase(it);
            vecIterator++;
            
            if (vecIterator == nums[row].end())
                break;
            
            ss.insert({*vecIterator, {vecIterator, row}});
        }
        
        return {low, high};
        
    }
};