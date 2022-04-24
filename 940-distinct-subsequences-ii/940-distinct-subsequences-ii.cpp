class Solution {
public:
    int dp[2007];
    
    int n;
    int M = 1000000007;
    string s;
    
    
    int solveIt(int idx) {
        if(idx == n) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int res = 0;
        bool mark[26] = {false};
        for(int i = idx; i < n; i++) {
            
            if(mark[s[i] - 'a'] == true) continue;
            
            mark[s[i] - 'a'] = true;
            
            res = (res + 1 + solveIt(i + 1)) % M;
        }
        
        return dp[idx] = res;
    }
    int distinctSubseqII(string s) {
        this -> s = s;
        memset(dp, -1, sizeof dp);
        n = s.length();
        
        return solveIt(0);
        
    }
};