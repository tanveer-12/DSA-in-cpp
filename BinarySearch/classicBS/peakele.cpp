/*   PEAK ELEMENT IN ARRAY
Given an array of length N, peak element is defined as the element greater than both 
of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and 
arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there 
are multiple peak numbers, return the index of any peak number. 

TC - O(logN)
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    int peakElement(std::vector<int> &nums){
        // edge case 1: if there is only one element
        if(nums.size() == 1){
            return 0;   // first index
        }
        // edge case 2: if first element is the peak
        if(nums[0] > nums[1]){
            return 0;
        }
        // edge case 3: if last element is the peak
        if(nums[nums.size() - 1] > nums[nums.size() - 2]){
            return nums.size() - 1; // index of last element
        }
        // search space for Binary search
        int low = 1, high = nums.size() - 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // if mid is the peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            // if the mid is greater than its left neighbor, means it is in increasing order
            // so peak must be in the right half
            if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }
            // else, the peak must be in the left half
            else{
                high = mid - 1;
            }
        }
        return 0;
    }
};

int main(){
    // Input array
    std::vector<int> nums = {1,10,13,7,6,5,4,2,1,0};

    // Create object
    Solution obj;

    // Output result
    std::cout << "Index of peak element is: "<<obj.peakElement(nums) << std::endl;
    return 0;
}