// Find the Majority Element that occurs more than N/2 times
// BRUTE FORCE APPROACH
/*
The steps are as follows:
    We will run a loop that will select the elements of the
    array one by one.
    Now, for each element, we will run another loop and 
    count its occurrence in the given array.
    If any element occurs more than the floor of (N/2), 
    we will simply return it.
*/

#include <iostream>
#include <vector>

int majorityElement(std::vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == arr[i]){
                cnt++;
            }
        }
        if(cnt > (n/2)){
            return arr[i];
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
