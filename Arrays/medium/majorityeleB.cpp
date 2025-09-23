// Find the Majority Element that occurs more than N/2 times
// BETTER SOLUTION: HASHING

/*
    Use a hashmap and store as (key, value) pairs.  
    Here the key will be the element of the array and the 
    value will be the number of times it occurs. 
    Traverse the array and update the value of the key. 
    Simultaneously check if the value is greater than the 
    floor of N/2. 
        If yes, return the key 
        Else iterate forward.
*/

#include <bits/stdc++.h>


int majorityElement(std::vector<int> arr){
    int n = arr.size();
    std::map<int, int> mpp;
    // storing the elements into hashmap with their count
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    //searching the hashmap for the majority element
    for(auto itr: mpp){
        if(itr.second > (n/2)){
            return itr.first;
        }
    }
    return -1;
}

int main(){
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    std::cout<<"Enter array elements: ";
    std::vector<int> nums(n);
    for(int i=0; i<n; i++){
        std::cin>>nums[i];
    }
    std::cout<<"The majority element is: "<<majorityElement(nums);
    return 0;
}