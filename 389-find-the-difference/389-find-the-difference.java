class Solution {
    public char findTheDifference(String s, String t) {
        int n = s.length();
        char[] s1 = new char[n];
        char[] t1 = new char[n + 1];
        s1 = s.toCharArray();
        t1 = t.toCharArray();
        Arrays.sort(s1);
        Arrays.sort(t1);
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != t1[i])
                return t1[i];
        }
        
        return t1[n];
    }
}