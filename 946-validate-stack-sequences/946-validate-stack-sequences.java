class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        
        int n = pushed.length;
        int m = popped.length;
        
        if (n == 0 && m != 0)
            return false;
        
        if (n == 0 && m == 0)
            return true;
        
        int i = 1, j = 0;
        stack.push(pushed[0]);
        
        while (i < n && j < m) {
            
            if (!stack.isEmpty() && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            } else {
                stack.push(pushed[i]);
                i++;   
            }
        }
        
        while (j < m) {
            if (stack.peek() != popped[j])
                return false;
            
            stack.pop();
            j++;
        }
        
        return true;
        
    }
}