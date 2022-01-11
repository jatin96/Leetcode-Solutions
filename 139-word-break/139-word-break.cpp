class Solution {
public:
    int n, len;
    string str;
    map <string, bool > mm;
    int dp[307];
    
    int solveIt(int idx) {
        
        if (idx == len)
            return 1;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        for (int i = idx; i < len; i++) {
            string pref = str.substr(idx, i - idx + 1);
            if(mm.find(pref) != mm.end()) {
                bool res = solveIt(i + 1);
                if(res) 
                    return dp[idx] = 1;
            }
        }
        
        return dp[idx] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = wordDict.size();
        len = s.length();
        str = s;
        memset(dp, -1, sizeof dp);
        
        for(int i = 0; i < n; i++)
            mm[wordDict[i]] = true;
        
        return solveIt(0);
    }
};