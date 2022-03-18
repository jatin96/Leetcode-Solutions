class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        int[] last = new int[26];
        boolean[] vis = new boolean[26];
        Arrays.fill(vis, false);
        int n = s.length();
        for (int i = 0; i < n; i++) { last[s.charAt(i) - 'a'] = i; }
        
        for (int i = 0; i < n; i++) {
            
            if (vis[s.charAt(i) - 'a']) 
                continue;
            
            while (!stack.isEmpty() && s.charAt(i) < stack.peek() && last[stack.peek() - 'a'] > i) {
                vis[stack.peek() - 'a'] = false;
                stack.pop();
            }
            
            stack.push(s.charAt(i));
            vis[s.charAt(i) - 'a'] = true;
        }
        
        StringBuilder str = new StringBuilder();
        while (!stack.isEmpty()) {
            str.append(stack.pop());
        }
        
        return str.reverse().toString();
        
    }
}