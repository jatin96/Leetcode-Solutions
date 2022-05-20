class Solution {
public:
    int getMaxFreq(vector<int>& freq) {
        int maxi = 0;
        for (int val : freq)
            maxi = max(maxi, val);
        
        return maxi;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int start = 0, res = 1;
        for (int end = 0; end < s.length(); end++) {
            freq[s[end] - 'A']++;
            int maxFreq = getMaxFreq(freq);
            while (end - start + 1 - maxFreq > k) {
                freq[s[start] - 'A']--;
                start++;
            }
            
            res = max(res, end - start + 1);
        }
        
        return res;
    }
};