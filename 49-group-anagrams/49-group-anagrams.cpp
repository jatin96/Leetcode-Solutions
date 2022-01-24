class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            anagramsMap[str].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for (auto anagrams: anagramsMap)
            res.push_back(anagrams.second);
        
        return res;
    }
};