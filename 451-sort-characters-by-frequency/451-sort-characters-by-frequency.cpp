class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<pair<int, char>> vec;
        int len = s.length();
        for (int i = 0; i < len; i++)
            freq[s[i]]++;
        
        for (auto it = freq.begin(); it != freq.end(); it++) {
            vec.push_back({it -> second, it -> first});
        }
        
        sort(vec.begin(), vec.end());
        
        string res = "";
        for (int i = vec.size() - 1; i >= 0; i--) {
            int cnt = vec[i].first;
            int ch = vec[i].second;
            string tmp(cnt, ch);
            res += tmp;
        }
        
        return res;
    }
};