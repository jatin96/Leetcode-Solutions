class Solution {
public:
    bool checkPalin(string str, int idx) {
        string new_str = str.substr(0, idx) + str.substr(idx + 1);
        
        int low = 0, high = new_str.length() - 1;
        while (low < high) {
            if(new_str[low] == new_str[high]) {
                low++;
                high--;
            }
            else 
                return false;
        }
        
        return true;   
    }
    
    bool validPalindrome(string str) {
        
        int low = 0, high = str.length() - 1;
        
        while (low < high) {
            if(str[low] == str[high]) {
                low++;
                high--;
            } else {
                return checkPalin(str,low) || checkPalin(str,high);       
            }
        }
        
        return true;
    }
};