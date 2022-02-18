class Solution {
public:
    string smallestSubsequence(string s) {
             string res = "";
        
        bool vis[26] = {false};
        int last[26] = {};
        
        for (int i = 0; i < s.length(); i ++) 
            last[s[i] - 'a'] = i;
        
        
        for (int i = 0; i < s.length(); i++) {
            
            if (vis[s[i] - 'a'])
                continue;
            while (res.size() && res[res.size() - 1] > s[i] && last[res[res.size() - 1] - 'a'] > i) {
                vis[res[res.size() - 1] - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        
        return res;
    }
};