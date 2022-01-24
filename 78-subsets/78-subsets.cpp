class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    int n;
    void solveIt(int idx, vector<int> &set) {
        if (idx == n) {
            res.push_back(set);
            return;
        }
        
        set.push_back(nums[idx]);
        solveIt(idx + 1, set);
        set.pop_back();
        solveIt(idx + 1, set);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        this -> nums = nums;
        vector<int> set;
        solveIt(0, set);
        return res;
    }
};