class Solution {
    private boolean isInteger(String s) {
    try { 
        Integer.parseInt(s); 
    } catch(NumberFormatException e) { 
        return false; 
    } catch(NullPointerException e) {
        return false;
    }
    // only got here if we didn't return false
    return true;
}
    
    private int operation(int a, int b, String operator) {
        if (operator.charAt(0) == '/')
            return a / b;
        if (operator.charAt(0) == '*')
            return a * b;
        if (operator.charAt(0) == '-')
            return a - b;
        return a + b;
    }
    
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        
        for (String token : tokens) {
            if (isInteger(token))
                stack.push(Integer.parseInt(token));
            else {
                int b = stack.pop();
                int a = stack.pop();
                stack.push(operation(a, b, token));
            }
        }
        
        return stack.pop();
    }
}