class Solution {
public:
    double findMedian(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int median1 = -1, median2 = -1;
        if ((n + m) % 2 != 0) {
            int i = 0, j = 0;
            for (int count = 0; count <= (n+m) / 2; count++) {
                
                if(i != n && j != m) {
                    if(nums1[i] < nums2[j]) {
                        median1 = nums1[i];
                        i++;
                    } else {
                        median1 = nums2[j];
                        j++;
                    }
                }
                else if(i != n) {
                    median1 = nums1[i];
                    i++;
                }
                else {
                    median1 = nums2[j];
                    j++;
                }
                
                cout << "median1: " << median1 << endl;
            }
            return median1;
        } else {
            int i = 0, j = 0;
            for (int count = 0; count <= (n + m) / 2; count++) {
                median2 = median1;
                if(i != n && j != m) {
                    if (nums1[i] < nums2[j]) {
                        median1 = nums1[i];
                        i++;
                    } else {
                        median1 = nums2[j];
                        j++;
                    }
                }
                else if(i != n) {
                    median1 = nums1[i];
                    i++;
                }
                else {
                    median1 = nums2[j];
                    j++;
                } 
            }
            
            return (median1 + median2) / 2.0;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(nums1, nums2);
    }
};