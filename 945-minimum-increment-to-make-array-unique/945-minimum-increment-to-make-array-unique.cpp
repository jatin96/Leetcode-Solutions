class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        set <int> ss;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (ss.find(nums[i]) == ss.end()) {
                ss.insert(nums[i]);
            } else {
                int maxi = max(*ss.rbegin(), nums[i]);
                int newNum = maxi + 1;
                res = res + (newNum - nums[i]);
                ss.insert(newNum);
            }
        }
        
        return res;
    }
};