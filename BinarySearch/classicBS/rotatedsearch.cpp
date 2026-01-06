/* SEARCH IN ROTATED SORTED ARRAY I
Given an array arr[] of distinct elements, which was initially sorted in ascending 
order but then rotated at some unknown pivot, the task is to find the index of a 
target key.  If the key is not present in the array, return -1.

Brute Force approach would be linear search 
TC - O(N)
SC - O(1)

Binary Search optimized approach
TC - O(logN)
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    int search(std::vector<int>& nums, int target){
        // set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;
        // check till the search space is valid
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return mid;
            }
            // check if the left half is sorted
            if(nums[low] <= nums[mid]){
                // if target lies in the sorted left half, search there
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                // else search in the right half
                else{
                    low = mid + 1;
                }
            }
            // otherwise, right half is sorted
            else{
                // if target lies in the sorted right half, search there
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                // else search in the left half
                else{
                    high = mid - 1;
                }
            }
        }
        // if target is not found anywhere, return -1
        return -1;
    }
};

int main(){
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target=0;
    Solution sl;
    int result = sl.search(nums, target);
    std::cout<<"Index of the target key is: "<<result;
    return 0;
}