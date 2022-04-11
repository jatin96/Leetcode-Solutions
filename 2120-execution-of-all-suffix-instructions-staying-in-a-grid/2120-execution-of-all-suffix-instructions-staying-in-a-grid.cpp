class Solution {
public:
    int startX, startY;
    string s;
    int n, m;
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    int findMoves(int idx, int x, int y) {
        if (idx == m)
            return 0;
        
        int res = 0;
        if(s[idx] == 'U' && isValid(x - 1, y))
            res = 1 + findMoves(idx + 1, x - 1, y);
        else if (s[idx] == 'L' && isValid(x, y - 1))
            res = 1 + findMoves(idx + 1, x, y - 1);
        else if (s[idx] == 'R' && isValid(x, y + 1))
            res = 1 + findMoves(idx + 1, x, y + 1);
        else if (s[idx] == 'D' && isValid(x + 1, y))
            res = 1 + findMoves(idx + 1, x + 1, y);
        
        return res;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        m = s.size();
        this -> n = n;
        this -> s = s;
        vector<int> ans;
        startX = startPos[0];
        startY = startPos[1];
        for (int i = 0; i < m; i++) {
            int moves = findMoves(i, startX, startY);
            ans.push_back(moves);
        }
        
        return ans;
    }
};