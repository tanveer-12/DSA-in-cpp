// Leetcode 26-: removes duplicates from the sorted array 
/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element
appears only once. The relative order of the elements should
be kept the same. Then return the number of unique elements in nums.
*/

#include <bits/stdc++.h>

// brute approach
int removeBrute(std::vector<int> v){
    // using set data structure
    int n = v.size();
    std::set<int> st;
    //inserting unique elements into the set
    // since set only accepts unique elements in sorted manner
    for(int i=0; i<n; i++){
        st.insert(v[i]);
    }
    // iterating over the set
    int index = 0;
    for(auto itr:st){
        v[index] = itr;
        index++;
    }
    return index;
}

// optimal approach
int removeOptimal(std::vector<int> &nums){
    // using two pointer approach
    int n = nums.size();
    int i = 0;
    for(int j=1; j<n;j++){
        if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i++;
        }   
    }
    return (i+1);
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"Enter elements in sorted way: ";
    for(int i=0; i<n;i++){
        std::cin>>arr[i];
    }
    int uniCnt = removeBrute(arr);
    std::cout<<"Nmuber of unique elements in the array: "<<uniCnt<<std::endl;
    int cntOpt = removeOptimal(arr);
    std::cout<<"Num of unique elements using two pointers: "<<cntOpt;
    return 0;
}