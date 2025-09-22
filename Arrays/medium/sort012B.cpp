// Sort an array of 0s, 1s, and 2s
// the B in the filename is for the Better Approach

// Better Solution : Two pass

#include <iostream>
#include <bits/stdc++.h>

void sortArray(std::vector<int> &arr){
    int n = arr.size();
    int cnt0,cnt1,cnt2;
    for(int i=0; i<n; i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else{ cnt2++; }
    }
    for(int i=0; i<cnt0; i++){
        arr[i] = 0;
    }
    for(int i=cnt0; i<cnt0+cnt1; i++){
        arr[i] = 1;
    }
    for(int i=cnt0+cnt1; i<n; i++){
        arr[i] = 2;
    }
}

int main(){
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    std::vector<int> nums(n);
    std::cout<<"Enter array elements in 0s,1s and 2s: ";
    for(int i=0; i< n;i++){
        std::cin>>nums[i];
    }
    sortArray(nums);
    std::cout<<"After sorting the array into 0s, 1s and 2s: \n";
    for(int itr: nums){
        std::cout<<itr<<" ";
    }
    return 0;
}