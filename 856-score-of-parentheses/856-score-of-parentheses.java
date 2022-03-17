class Solution {
    public int scoreOfParentheses(String s) {
        return score(s,0,s.length()-1);
    }
    
    /**
    * st and end denote the indexes of string processed by the score method
    */
    public int score(String s,int st,int end){
        
        if(end>=s.length())return 0; // invalid string
        if(st>=end)return 0; // another invalid string
        if(st==end-1)return 1; // this means input string = `()`
        
        int openBracks=0;
        int closeBracks=0;
        int totalScore=0;
        int startPoint=st;
        for(int i=st;i<=end;i++){
            if(s.charAt(i)=='(')openBracks++;
            if(s.charAt(i)==')')closeBracks++;
            if(closeBracks==openBracks){ // found a string of type 1. - eg. () , (()()) etc.
                int result = score(s,startPoint+1,i-1);
                
                if(result!=0)
                    totalScore+=(2*result);
                else
                    totalScore+=1;
                
                startPoint=i+1; // update the startPoint
                openBracks=0; // reset open and close brackets count
                closeBracks=0;
            }
        }
        return totalScore;
    }
}