class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    string solveIt(string &s, int &i) {
        string digit, res = "";
        while ( i < s.length() && s[i] != ']') {
            if(!isdigit(s[i])) {
                res += s[i++];
            } else {
                    int n = 0;
                    while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    // to skip bracket
                    i++;
                    string ret = solveIt(s, i);
                    i++; // to skip bracket

                    while(n--) res += ret;
                    }
        }
        
        return res;
    }
    string decodeString(string s) {
        int i = 0;
       return solveIt(s, i); 
    }
};