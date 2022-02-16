class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        
        int n = plants.length;
        int alicePosition = 0;
        int bobPosition = n - 1;
        int aliceCan = capacityA, bobCan = capacityB;
        int res = 0;
        while (alicePosition <= bobPosition) {
            if (alicePosition == bobPosition) {
                int maxWater = Math.max(aliceCan, bobCan);
                if (maxWater < plants[alicePosition])
                    res++;
            } else {
                if (aliceCan < plants[alicePosition]) {
                    aliceCan = capacityA;
                    res++;
                }
                aliceCan -= plants[alicePosition];
               
                
                if (bobCan < plants[bobPosition]) {
                    bobCan = capacityB;
                    res++;
                }
                
                bobCan -= plants[bobPosition];  
            }
            
            alicePosition++;
            bobPosition--;
        }
        
        return res;
    }
}