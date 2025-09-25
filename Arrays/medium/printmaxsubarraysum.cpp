// printing the subarray having the maximum sum
// follow up from maxsubarraysum.cpp codes

#include <bits/stdc++.h>

long long maxSub(int arr[], int n){
    long long maxi=LONG_MIN, sum = 0;
    int start=0, startInd = -1, endInd = -1;

    for(int i=0; i<n; i++){
        if(sum == 0){
            start = i;
        }
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            startInd = start;
            endInd = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    // printing the subarray containing the max sum
    std::cout<<"Printing the subarray: ";
    for(int i=startInd; i<= endInd; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    return maxi;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxsum = maxSub(arr, n);
    std::cout<<"the maximum subarray sum is: "<<maxsum<<std::endl;
    return 0;
}