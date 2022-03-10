class Solution {
public:
    
    bool isWordValid(string currWord, string nextWord, vector<string> &currList) {
        
        int cnt = 0;
        for (int i = 0; i < currWord.length(); i++) {
            if (currWord[i] != nextWord[i]) {
                cnt++;
            }
        }
        
        if (cnt != 1)
            return false;
        
        for (int i = 0; i < currList.size(); i++) {
            if (currList[i] == nextWord)
                return false;
        }
        
        return true;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        
        queue<vector<string>> Q;
        
        unordered_set<string> ss;
        
        for (int i = 0; i < wordList.size(); i++) 
            ss.insert(wordList[i]);
        
        Q.push({beginWord});
        
        vector<vector<string>> res;
        
        while (!Q.empty()) {
            int n = Q.size();
            bool flag = false;
            for (int i = 0; i < n; i++) {
                 vector<string> currList = Q.front();
                Q.pop();
                
                if (currList.back() == endWord) {
                    res.push_back(currList);
                    flag = true;
                    continue;
                }
                
                string currWord = currList.back();
                ss.erase(currWord);
                for (int j = 0; j < currWord.length(); j++) {
                    string newWord = currWord;
                    for (int k = 0; k < 26; k++) {
                        newWord[j] = (char)(k + 'a');
                        if (ss.find(newWord) != ss.end()) {
                            vector<string> newList = currList;
                            newList.push_back(newWord);
                            Q.push(newList);
                        }
                    } 
                }
                
            }
            if (flag == true)
                break;
        }
        
        return res;
    }
};