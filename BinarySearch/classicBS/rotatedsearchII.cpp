/*  SEARCH ELEMENT IN ROTATED SEARCH ARRAY II
Given an integer array arr of size N, sorted in ascending order 
(may contain duplicate values) and a target value k. Now the array is 
rotated at some pivot point unknown to you. Return True if k is present and 
otherwise, return False. 

Same as rotatedsearch.cpp but this time, the array might contain duplicates
TC - O(logN) for Best case, O(N/2) for worst
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    bool search(std::vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        while(low <=high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return true;
            }
            // edge case: when all three are equal, we cannot determine which side is sorted
            if(nums[low] == nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            // if the left half is sorted
            if(nums[low] <= nums[mid]){
                // if target lies in the left half, search there
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // otherwise the right half is sorted
            else{
                // if target lies in the sorted right half, search there
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        // if target is not found anywhere, return false
        return false;
    }
};

int main(){
    std::vector<int> nums = {7,8,1,2,3,3,3,4,5,6};
    int target = 3;
    Solution obj;
    bool result = obj.search(nums, target);
    if(result == true){
        std::cout<<"The target is present in the array";
    }
    else{
        std::cout<<"The target is not present in the array";
    }
    return 0;
}
