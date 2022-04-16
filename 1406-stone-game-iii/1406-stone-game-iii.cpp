class Solution {
public:
    
    int dp[50007];
    vector<int> stoneValue;
    int n;
    int solveIt(int idx) {
        if (idx == stoneValue.size())
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        int curr = stoneValue[idx], diff = curr - solveIt(idx + 1);
        for(int i = idx + 1; i < min(n, idx + 3); i++) {
            curr += stoneValue[i];
            diff = max(diff, curr - solveIt(i + 1));
        }
        
        return dp[idx] = diff;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof dp);
        this -> stoneValue = stoneValue;
        n = stoneValue.size();
        int res = solveIt(0);
        
        if (res == 0)
            return "Tie";
        else if (res > 0)
            return "Alice";
        else 
            return "Bob";
    }
};