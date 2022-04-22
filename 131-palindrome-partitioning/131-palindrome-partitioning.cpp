class Solution {
public:
    int n;
    string s; 
    unordered_map<int, vector<vector<string>> > dp;
    bool isPalindrome(string str) {
        int low = 0, high = str.length() - 1;
        while (low < high) {
            if (str[low] != str[high])
                return false;
            low++;
            high--;
        }
        
        return true;
    }
    
    vector<vector<string>> solveIt(int start) {
        
        if (start == n) {
            return {{""}};
        }
        if (start == n - 1) {
            string tmp(1, s[start]);
            return {{tmp}};
        }
        
        if (dp.find(start) != dp.end()) return dp[start];
        
        vector<vector<string>> res;
        for (int i = start; i < n; i++) {
            string str = s.substr(start, i - start + 1);
            if (isPalindrome(str)) {
                vector<vector<string>> tmp = solveIt(i + 1);
                for (int j = 0; j < tmp.size(); j++) {
                    tmp[j].push_back(str);
                    res.push_back(tmp[j]);
                }
            }
        }
        
        return dp[start] = res;
    }
    vector<vector<string>> partition(string s) {
        this -> s = s;
        n = s.length();
        dp.clear();
        
        vector<vector<string>> ans = solveIt(0);
        
        for (int i = 0; i < ans.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
            if (ans[i].back() == "") ans[i].pop_back();
        }
        
        return ans;
    }
};