class Solution {
    
    private boolean predicate(int[] position, int m, int maxDist) {
        int balls = m;
        int nextBall = position[0] + maxDist;
        balls--;
        
        for (int i = 1; i < position.length; i++) {
            int currBall = position[i];
            
            if (currBall >= nextBall) {
                balls--;
                nextBall = currBall + maxDist;
            }
        }
        
        if(balls <= 0)
            return true;
        
        return false;
    }
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        
        int low = 1, high = Math.abs(position[0] - position[position.length - 1]), mid;
        int ans = 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (predicate(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
}