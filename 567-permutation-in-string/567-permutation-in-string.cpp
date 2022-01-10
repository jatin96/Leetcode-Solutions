class Solution {
public:
    bool checkInclusion(string sub_str, string str) {
        int sub_len = sub_str.length();
        int len = str.length();
        
        int sub_freq[26] = {}, window_freq[26] = {};
        for (int i = 0; i < sub_len; i++)
            sub_freq[sub_str[i] - 'a']++;
        
        if (sub_len > len) return false;
        
        for (int i = sub_len - 1; i < len; i++) {
            if (i == sub_len - 1) {
                for (int j = 0; j < sub_len; j++)
                    window_freq[str[j] - 'a']++;
            } else {
                window_freq[str[(i - sub_len + 1) - 1] - 'a']--;
                window_freq[str[i] - 'a']++;
            }
            bool flag = false;
            for (int i = 0; i < 26; i++) {
                if (window_freq[i] != sub_freq[i]) {
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                return true;
        }
        
        return false;
    }
};