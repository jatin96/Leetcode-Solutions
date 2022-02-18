class Solution {
    boolean isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    public long countVowels(String word) {
        long len = word.length();
        long res = 0;
        for (int i = 0; i < len; i++){
            if ("aeiou".indexOf(word.charAt(i)) >= 0)
                res += (i + 1) * (len - i);  
        }
        
        return res;
    }
    
}