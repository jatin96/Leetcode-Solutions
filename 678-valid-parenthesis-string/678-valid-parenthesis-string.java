class Solution {
    public boolean checkValidString(String s) {
        int len = s.length();
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> aster = new Stack<>();
        
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '(')
                stack.push(i);
            else if (s.charAt(i) == '*')
                aster.push(i);
            else if (s.charAt(i) == ')') {
                if (!stack.isEmpty())
                    stack.pop();
                else if (!aster.isEmpty())
                    aster.pop();
                else 
                    return false;
            }
        }
        
        
        while (!stack.isEmpty() && !aster.isEmpty()) {
            if (stack.peek() > aster.peek()) return false;
            stack.pop();
            aster.pop();
        }
        
        return stack.isEmpty();
    }
}