class Solution {
    enum SIGN {
        greater,
        smaller,
        neutral;
    }
    
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length;
        int localMax = 1;
        int globalMax = 1;
        SIGN flag = SIGN.neutral;
        for (int i = 1; i < n; i ++) {
            if (flag == SIGN.neutral) {
                if (arr[i] > arr[i - 1]) {
                    flag = SIGN.greater;
                    localMax += 1;
                } else if (arr[i] < arr[i - 1]) {
                    flag = SIGN.smaller;
                    localMax += 1;
                }
            }
            else if (flag == SIGN.smaller && arr[i] > arr[i - 1]) {
                flag = SIGN.greater;
                localMax += 1;
            }
            else if (flag == SIGN.greater && arr[i] < arr[i - 1]) {
                flag = SIGN.smaller;
                localMax += 1;
            }
            else {
                if (arr[i] > arr[i - 1]) {
                    flag = SIGN.greater;
                    localMax = 2;
                } else if (arr[i] < arr[i - 1]) {
                    flag = SIGN.smaller;
                    localMax = 2;
                }
                else {
                    flag = SIGN.neutral;
                    localMax = 1;
                }
            }
            
            globalMax = Math.max(globalMax, localMax);
        }
        
        return globalMax;
        
    }
}