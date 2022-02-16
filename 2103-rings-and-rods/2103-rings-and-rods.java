class Solution {
    public int countPoints(String rings) {
        int[][] rod = new int[10][3];
        
        for (int i = 0; i < rings.length(); i += 2) {
            char ch = rings.charAt(i);
            int pos = rings.charAt(i + 1) - '0';
            
            if(ch == 'R')
                rod[pos][0] = 1;
            else if (ch == 'G')
                rod[pos][1] = 1;
            else
                rod[pos][2] = 1;
        }
        
        int res = 0;
        for (int i = 0; i < 10; i ++) {
            if(rod[i][0] == 1 && rod[i][1] == 1 && rod[i][2] == 1)
                res++;
        }
        
        return res;
    }
}