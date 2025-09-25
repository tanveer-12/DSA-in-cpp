// Maximum Subarray Sum in an Array
// BETTER SOLUTION
// TC - O(N^2) = two nested loops
// SC - O(1) = not using any extra space

#include <bits/stdc++.h>

int maxSubarraysum(int arr[], int n){
    int maxi = INT_MIN;     //maximum sum
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            // subarray = arr[i....j]

            // add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];
            maxi = std::max(maxi, sum);
        }
    }
    return maxi;
}

int main(){
    int arr[] = {-2,-3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 9*4 / 4
    int maxSum = maxSubarraysum(arr, n);
    std::cout<<"The maximum subarray sum is: "<<maxSum<<std::endl;
    return 0;
}