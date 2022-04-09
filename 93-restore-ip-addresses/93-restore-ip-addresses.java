class Solution {
    List<String> res = new ArrayList<>();
    String s;
    
    boolean isValidInteger(String str) {
        if (str.length() == 1)
            return true;
        
        if (str.charAt(0) == '0')
            return false;
        
        int num = Integer.parseInt(str);
        if (num >= 10 && num <= 255)
            return true;
        
        return false;
    }
    
    void solveIt(int idx, String currStr, int dotcnt) {
        
        if (idx == s.length() && dotcnt == 4) {
            currStr = currStr.substring(0, currStr.length() - 1);
            res.add(currStr);
            return;
        }
        
        for (int i = idx; i < s.length(); i++) {
            if (i - idx + 1 > 3)
                break;
            
            String str = s.substring(idx, i + 1);
            
            if (isValidInteger(str) && dotcnt + 1 <= 4)
                solveIt(i + 1, currStr + str + ".", dotcnt + 1);
        }
        
    }
    public List<String> restoreIpAddresses(String s) {
        
        if (s.length() > 12 || s.length() < 4)
            return res;
        this.s = s;
        String str = "";
        solveIt(0, str, 0);
        return res;
    }
}