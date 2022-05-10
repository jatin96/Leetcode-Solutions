class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> occ_idx[26];
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            occ_idx[s[i] - 'a'].push_back(i);
        }
        
        int m = words.size(), res = 0;
        for (int i = 0; i < m; i++) {
            string word = words[i];
            int len  = word.length();
            
            if (occ_idx[word[0] - 'a'].size() == 0)
                continue;
            
            int pos = occ_idx[word[0] - 'a'][0];
            int flag = 0;
            for (int j = 1; j < len; j++) {
                char ch_idx = word[j] - 'a';
                
                int tmp_idx = upper_bound(occ_idx[ch_idx].begin(), occ_idx[ch_idx].end(), pos) - occ_idx[ch_idx].begin();
                if (tmp_idx == occ_idx[ch_idx].size()) {
                    flag = 1;
                    break;
                }
                pos = occ_idx[ch_idx][tmp_idx];
            }
            
            if(flag == 1)
                continue;
            
            res++;
        }
        
        return res;
    }
};