/*  MINIMUM IN A SORTED ROTATED ARRAY
Given an integer array arr of size N, sorted in ascending order (with 
distinct values), the array is rotated at any index which is unknown. Find 
the minimum element in the array. 

TC - 
SC - 
*/

#include <bits/stdc++.h>

class Solution{
public:
    int minSearch(std::vector<int> &nums){
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            // check which half to discard
            if(nums[mid] > nums[high]){
                // minimum lies in the right half
                low = mid + 1;
            }
            else{
                // minimum lies in the left half
                // (including mid)
                high = mid;
            }
        }
        // return the minimum element
        return nums[low];
    }
};

int main(){
    
    // Input array
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.minSearch(nums);

    // Output the result
    std::cout << "Minimum element is " << result << std::endl;
    return 0;
}