class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                
                if (sum == target)
                {
                    res.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        
        vector<vector<int>> ans;
        for (auto it : res)
            ans.push_back(it);
        return ans;
    }
};