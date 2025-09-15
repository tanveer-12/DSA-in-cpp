// Leetcode 283: Move all 0's to end of the array while
// maintaining the relative order of the non-zero elements


#include <bits/stdc++.h>

// brute force
void moveBrute(std::vector<int> &nums){
    int n = nums.size();
    // creating temp vector to store non-zero elements
    std::vector<int> temp;
    for(int i=0; i<n;i++){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        }
    }
    // storing the elements from temp to the front of the array
    for(int i=0; i<temp.size();i++){
        nums[i] = temp[i];
    }
    // assigning 0 to all the remaining indexes
    int cntnonzero = temp.size();
    for(int i=cntnonzero; i<n; i++){
        nums[i] =0; 
    }
}


// OPTIMIZED
void moveOptimal(std::vector<int> &nums){
    int j=-1;
    int n=nums.size();
    // finding first zero element index
    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = j+1; i<n; i++){
        if(nums[i] != 0){
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main(){
    std::vector<int> arr = {1,0,2,3,0,0,4,5,1};
    moveBrute(arr);
    moveOptimal(arr);
    for(auto itr: arr){
        std::cout<<itr<<" ";
    }
    return 0;
}