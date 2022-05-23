class Solution {
public:
int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        // If odd jump possible for indexes
        vector<bool> oddJumpPossibleFrom(n, false);
        // If even jump possible for indexes
        vector<bool> evenJumpPossibleFrom(n, false);
        
        // Last index is the array has no value after it.
        // So conceptually both odd and even jumps are possible from it (to no value)
        oddJumpPossibleFrom[n - 1] = true;
        evenJumpPossibleFrom[n - 1] = true;
        
        // Map between element value vs it's index
        map<int, int> elementToIdxMap;
        // Put the last element vs it's index into it
        elementToIdxMap[arr[n - 1]] = n - 1;
        
        // Last point is always good starting point
        int totalGoodStartingPoints = 1;
        
        // Loop from the second last element toward the left
        for (int i = n - 2; i >= 0; i--) {
            // Odd jump condition: arr[i] <= arr[j]
            // So we need to find element at j which is the smallest greater (or equal) element than element at i
            // lower_bound finds first element >= element at i
            // And as we are using a sorted map, this element is the smallest possible greater element
            auto greaterElementForOddJump = elementToIdxMap.lower_bound(arr[i]);
            
            // Even jump condition: arr[i] >= arr[j]
            // So we need to find element at j which is the largest smaller (or equal) element than element at i
            // upper_bound finds first element > element at i
            // So the previous element of it is the last element <= element at i
            // And as we are using a sorted map, this element is the largest possible smaller element
            auto smallerElementForEvenJump = elementToIdxMap.upper_bound(arr[i]);
            
            // If suitable element exists to perform an odd jump
            if (greaterElementForOddJump != elementToIdxMap.end()) {
                // Odd jump is possible from this index i if from next element an even jump is possible
                // greaterElementForOddJump->first is the value of the element
                // greaterElementForOddJump->second is the index of the element
                oddJumpPossibleFrom[i] = evenJumpPossibleFrom[greaterElementForOddJump->second];
            }
            
            // If suitable element exists to perform an even jump
            // Keep in mind that upper_bound returns first element > element at i
            // So to find the last smaller or equal element we need need to decrement the desired "smallerElementForEvenJump"
            // Also note that if upper_bound can't find the number > element, then it returns the last element in the range
            if (smallerElementForEvenJump != elementToIdxMap.begin()) {
                // As described above, upper_bound finds first element > element at i
                // So decrement the iterator to find the last element <- element at i
                smallerElementForEvenJump--;
                
                // Even jump is possible from this index i if from next element an odd jump is possible
                // smallerElementForEvenJump->first is the value of the element
                // smallerElementForEvenJump->second is the index of the element
                evenJumpPossibleFrom[i] = oddJumpPossibleFrom[smallerElementForEvenJump->second];
            }
            
            // First jump (jump no 1) is always an odd jump
            // So if from this `ith` number an odd jump can be made, then this is a good starting point.
            // In that case increment the count for good starting point.
            if (oddJumpPossibleFrom[i]) {
                totalGoodStartingPoints++;
            }
            
            // We did the necessary work for element at index i.
            // Now put in into the map so that we can use it for the previous items
            // Notice that element is added into the map at the last of the iteration so that itself is not couted when we are looking for the next element to jump at
            elementToIdxMap[arr[i]] = i;
        }
        
        // Return total good starting points
        return totalGoodStartingPoints;
    }
};