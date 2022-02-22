class Solution {
public:
    int titleToNumber(string str) {
        int n = str.length();
        
        long long res = 0;
        long long p = 1;
        for (int i = n - 1; i >= 0; i--) {
            res += p * (str[i] - 'A' + 1);
            p *= 26;
        }
        
        return res;
    }
};