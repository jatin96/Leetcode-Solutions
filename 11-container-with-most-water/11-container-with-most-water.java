class Solution {
    public int maxArea(int[] height) {
        int low = 0, high = height.length - 1;
        
        int maxi = 0;
        while (low < high) {
            
            maxi = Math.max((high - low) * Math.min(height[low], height[high]), maxi);
            
            if (height[low] < height[high])
                low++;
            else
                high--;
        }
        
        return maxi;
    }
}