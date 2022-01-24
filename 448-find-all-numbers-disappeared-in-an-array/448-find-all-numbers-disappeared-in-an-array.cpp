class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            
            if (nums[idx] > 0)
                nums[idx] = -1 * nums[idx];
        }
        
        for (int i = 1; i <= nums.size(); i++)
            if(nums[i - 1] > 0)
                res.push_back(i);
        
        return res;
    }
};