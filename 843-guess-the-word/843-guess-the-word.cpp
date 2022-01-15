/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
           vector<string> reducelist(vector<string> &wordlist, string guess, int d) {
        vector<string> reducedlist;
        for (auto &word: wordlist) {
            if (match(word, guess) == d) reducedlist.push_back(word); 
        }
        return reducedlist;
    }
    
    int match(string from, string to) {
        int d = 0, n = from.length();
        for (int i = 0; i < n; i ++) {
            if (from[i] == to[i]) d ++;
        }
        return d;
    }
    
    int wordsRemoved(string guess, string secret, vector<string> &wordList) {
        int d = match(guess, secret);
        int remove = 0;
        for (auto &word: wordList) {
            auto d1 = match(guess, word);
            if (d != d1) remove ++; 
        }
        return remove;
    }
    
    // Minimax.. get best word to guess
    string minimax(vector<string>& wordList) {
        int n = wordList.size();
        map<string, int> count;
        for (auto &word: wordList) count[word] = INT_MAX;
        for (auto &guess: wordList) {
            for (auto &secret: wordList) {
                count[guess] = min(count[guess], wordsRemoved(guess, secret, wordList));       
            }
        }
        int max = INT_MIN;
        string res;
        for (auto &word: wordList) {
            if (count[word] > max) {
                max = count[word];
                res = word;
            }
        }
        return res;
    }
    
    
    void findSecretWord(vector<string>& wordlist, Master& master) {

        // we need to reduce the search space in some way. Otherwise we need to guess every word as a guess. 
        // The only information we have after making a guess is the number of matches the word will has with the secret
        
        // i. Guess the word -> say the distance is x
        // ii. remove the words which are not at distance x from word in search space

        // But... How do we know which word to choose? 
        // We have to choose that word as our guess, which will maximize the (minimum number of words which can be removed if that word is chosen as the guess (for this we need to consider every other word as the secret word and see how many words are being removed))

        auto reducedlist = wordlist;
        
        while (true) {
            auto guess = minimax(reducedlist);
            int d = master.guess(guess);
            // cout << guess << " " << d << endl;
            if (d == 6) break;
            reducedlist = reducelist(reducedlist, guess, d);
            // cout << reducedlist.size() << endl;
        }
        
    }
};