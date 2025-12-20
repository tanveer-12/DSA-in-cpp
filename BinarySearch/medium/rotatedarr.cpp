/*
Given an integer array nums, sorted in ascending order (with distinct values) and 
a target value k. The array is rotated at some pivot point that is unknown. Find 
the index at which k is present and if k is not present return -1.

TC - O(N)
SC - O(1)

Examples:
Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given 
rotated sorted array, nums. Thus, we get output as 4, which is the index at which
0 is present in the array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output :-1
Explanation :Here, the target is 3. Since 3 is not present in the given 
rotated sorted array. Thus, we get the output as -1.

BRUTE FORCE SOLUTION: LINEAR SEARCH
*/

#include <bits/stdc++.h>

class Solution {
public:
    // Function to search target in rotated sorted array using brute force
    int search(std::vector<int>& nums, int target){
        // loop through each element in the array
        for(int i=0; i<nums.size(); i++){
            // if current element matches target, return index
            if(nums[i] == target){
                return i;
            }
        }
        // if not found, return -1
        return -1;
    }
};

int main(){
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution obj;
    int index = obj.search(nums, target);
    std::cout<<"The resultant index is: "<<index;
    return 0;
}