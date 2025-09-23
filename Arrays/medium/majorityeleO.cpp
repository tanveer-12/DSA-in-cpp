// Find the Majority Element that occurs more than N/2 times
// OPTIMAL SOLUTION: MOORE's VOTING ALGO

/*
Approach: 
    Initialize 2 variables:
    Count –  for tracking the count of element
    Element – for which element we are counting
    Traverse through the given array.
        If Count is 0 then store the current element of the 
        array as Element.
        If the current element and Element are the same increase 
        the Count by 1.
        If they are different decrease the Count by 1.
    The integer present in Element should be the result we are 
    expecting 
*/

#include <bits/stdc++.h>

int majorityElement(std::vector<int> arr){
    int n = arr.size();
    int el, cnt=0;
    for(int i=0; i<n; i++){
        if(cnt==0){
            cnt = 1;
            el = arr[i];
        }
        else if(el == arr[i]){
            cnt++;
        }
        else {
            cnt--;
        }
    }
    int cnt1=0;
    //checking if the el is majority or not
    for(int i=0; i<n; i++){
        if(arr[i] == el)
        {
            cnt1++;
        }
    }
    if(cnt1 > (n/2)){
        return el;
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