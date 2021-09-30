class Solution {
public:
    int mark[26];
    string convertToNormal(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = (char)(mark[str[i] - 'a'] + 'a');
        }
        
        return str;
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++) {
            mark[order[i] - 'a'] = i;
        }
        
        for(int i = 0; i < words.size(); i++) {
            words[i] = convertToNormal(words[i]);
        }
        
        return is_sorted(words.begin(), words.end());
        
    }
};