// sorting the array into 0s ,1s and 2s 
// the 'O' in the filename is for the Optimal solution

// OPTIMAL SOLUTION: DUTCH NATIONAL FLAG ALGORITHM

#include <bits/stdc++.h>

void sortArray(std::vector<int> &nums){
    int n= nums.size();
    int low=0, mid=0, high=n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            std::swap(nums[high], nums[mid]);
            high--;
        }
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