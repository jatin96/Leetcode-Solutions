class Solution {
public:
    bool isValid(string a, string b) {
        string c,d;
        
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != 'X') c.push_back(a[i]);
            if (b[i] != 'X') d.push_back(b[i]);
        }
        
        return c == d;
    }
    bool canTransform(string start, string end) {
        if (!isValid(start, end))
            return false;
        
        int j = 0;
        for (int i = 0; i < start.length(); i++) {
            
            if (start[i] == 'X') continue;
            
            while (j < end.length() && start[i] != end[j])
                j++;
            
            if (start[i] == 'L' && j > i)
                return false;
            if (start[i] == 'R' && j < i)
                return false;
            
            j++;
        }
        
        return true;
    }
};