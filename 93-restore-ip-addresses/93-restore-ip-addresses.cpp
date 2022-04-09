class Solution {
public:
    string s;
    vector<string> res;
    bool isValidInteger(string str) {
        if (str.length() == 1)
            return true;
        
        if (str[0] == '0')
            return false;
        
        int num = stoi(str);
        if (num >= 10 && num <= 255)
            return true;
        
        return false;
    }
    
    void solveIt(int idx, string currIp, int dotcnt) {
        
        if (idx == s.length() && dotcnt  == 4) {
            currIp.pop_back();
            res.push_back(currIp);
            return ;
        }
        
        for (int i = idx; i < s.length(); i++) {
            if (i - idx + 1 > 3)
                break;
            
            string ip = s.substr(idx, i - idx + 1);
            if (isValidInteger(ip) && dotcnt + 1 <= 4) {
                solveIt(i + 1, currIp + ip + ".", dotcnt + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this -> s = s;
        if (s.length() > 12)
            return res;
        
        solveIt(0, "", 0);
        
        return res;
    }
};