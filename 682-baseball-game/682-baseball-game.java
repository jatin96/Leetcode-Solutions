class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < ops.length; i++){
            String str = ops[i];
            
            if (str.charAt(0) == 'D') {
                stack.push(stack.peek() * 2);
            }
            else if (str.charAt(0) == 'C')
                stack.pop();
            else if (str.charAt(0) == '+') {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(b);
                stack.push(a);
                stack.push(a + b);
            }
            else
                stack.push(Integer.parseInt(str));
        }
        
        int res = 0;
        while (!stack.isEmpty())
            res += stack.pop();
        
        return res;
    }
}