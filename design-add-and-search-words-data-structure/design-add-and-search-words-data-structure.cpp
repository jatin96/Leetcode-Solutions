class WordDictionary {
    private:
    struct Node {
        bool flag;
        struct Node *links[26];
        Node() {
            flag = false;
            for (int i = 0; i < 26; i++)
                links[i] = NULL;
        }
        
        void put(char ch, Node *node) {
            links[ch - 'a'] = node;
        }
        
        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }
        
        Node * next(char ch) {
            return links[ch -'a'];
        }
        
        void setEnd() {
            flag = true;
        }
        
        bool isEnd() {
            return flag;
        }
    };
    
    void insert(string word, Node * root) {
        int len = word.length();
        
        for (int i = 0; i < len; i ++) {
            if (!(root -> containsKey(word[i])))
                root -> put(word[i], new Node());
            
            root = root -> next(word[i]);
        }
        
        root -> setEnd();
    }
    bool find(Node * root, string word, int idx) {
        
        // cout << word << " , " << idx << endl;
        if(idx == word.length())
            return root -> isEnd();
        
        if(word[idx] != '.') {
            if (root -> containsKey(word[idx]))
                return find(root -> next(word[idx]), word, idx + 1);
            return false;
        }
        
        for (int i = 0; i < 26; i++) {
            if(root -> containsKey((char)('a' + i))) {
                bool res = find(root -> next((char)('a' + i)), word, idx + 1);
                if (res) return true;
            }
        }
        
        return false;
    }
public:
    Node * root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        insert(word, root);
    }
    
    bool search(string word) {
        return find(root, word, 0);
    }
};