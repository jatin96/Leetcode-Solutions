class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        
        int i = 0;
        int j = 1;
        path = path + "/";
        int n = path.length();
        String directory = "";
        while (j < n) {
            
            if (path.charAt(j) == '/') {
                if(!stack.isEmpty() && directory.equals(".."))
                    stack.pop();
                else if (!directory.equals(".") && !directory.equals("") && !directory.equals("..")) {
                   stack.push(directory);
                }
                directory = "";
                j = j + 1;
            }
            else {
                directory += path.charAt(j);
                j = j + 1;
            }
           
        }
        
         return constructPath(stack);
    }
    
    private String constructPath(Stack<String> stack) {
        String res = "";
        while (!stack.isEmpty())
        {
            StringBuilder tmp = new StringBuilder(stack.pop());
            tmp.reverse();
            res = res + tmp.toString() + "/";
        }
        
        if (res.equals(""))
            res += "/";
        
        StringBuilder sb = new StringBuilder(res);
        
        return sb.reverse().toString();
    }
    
  
}