// Leetcode 1752. Check if Array Is Sorted and Rotated

/*
Given an array nums, return true if the array was originally
sorted in non-decreasing order, then rotated some number 
of positions (including zero). Otherwise, return false.
*/

#include <bits/stdc++.h>

bool check(std::vector<int> &nums){
    int n = nums.size();
    int count =0;
    for(int i=0; i<n;i++){
        if(nums[i] > nums[(i+1) % n]){
            count++;
        }
    }
    return count <=1;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i=0; i<n; i++){
        std::cin>>arr[i];
    }
    bool res = check(arr);
    if(res){
        std::cout<<"Array is Sorted and Rotated";
    }
    else{
        std::cout<<"Array is not sorted and rotated";
    }
    return 0;
}