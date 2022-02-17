class Solution {
public:
    int n;
    vector<vector<int>> res;
    void solveIt(vector<int> &candidates, int idx, int target, vector<int> &ans) {
        
        if(target == 0) {
            res.push_back(ans);
            return ;
        }

        
        if(idx == n)
            return ;
        
        vector<vector<int>> res, tmp2;
        for(int i = 0; i * candidates[idx] <= target; i++) {
            
            for(int j = 0; j < i; j++)
                ans.push_back(candidates[idx]);
            
            solveIt(candidates, idx + 1, target - candidates[idx] * i, ans);
            
            for(int j = 0; j < i; j ++)
                ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int>ans;
        solveIt(candidates, 0, target, ans);
        return res;
    }
};