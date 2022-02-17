class Solution {
public:
    int n, diff;
    int dp[100007];
    vector<int> arr;
    unordered_map<int, vector<int>> numIndex;
    int solveIt(int idx) {
        if (idx >= n)
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        vector<int> vec;
        if (numIndex.find(arr[idx] + diff) != numIndex.end())
            vec = numIndex[arr[idx] + diff];
        
        int res = 1;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] <= idx)
                continue;
            
            res = max(res, 1 + solveIt(vec[i]));
        }
        
        return dp[idx] = res;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        n = arr.size();
        this -> arr = arr;
        diff = difference;
        memset(dp, -1, sizeof dp);
        
        for (int i = 0; i < n; i++) {
            numIndex[arr[i]].push_back(i);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, solveIt(i));
        }
        
        return res;
    }
};