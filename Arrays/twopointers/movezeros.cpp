/*
You have to move all the zeros in the array to the right end while maintaining the 
relative order of the non-zero elements. The operation must be performed in place, 
meaning you should not use extra space for another array.

TC - O(n)
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    void moveZeros(std::vector<int> &nums){
        //pointer to the first zero
        int j = -1;

        // finding the first zero
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        // if no zero is found in the array
        if(j == -1) return;

        // starting from the next index of the first zero
        for(int i=j+1; i<nums.size(); i++){
            // if current element is not zero
            // swap the nums[i] and nums[j]
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                // move j to the next zero
                j++;
            }
        }
    }
};


int main(){
    Solution sl;
    std::vector<int> nums = {1,2,4,3,0,0,5,0};
    sl.moveZeros(nums);

    // printing the result
    for(int num :nums) std::cout<<num<<" ";
    std::cout<<std::endl;
    return 0;
}

