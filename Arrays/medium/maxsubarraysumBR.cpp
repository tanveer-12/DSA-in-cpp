// Maximum Subarray Sum in an Array
// BRUTE FORCE
// TC - O(N^3) = three nested loops
// SC - O(1) = not using any extra space


#include <bits/stdc++.h>

int maxSubarraysum(int arr[], int n){
    int maxi = INT_MIN;     //maximum sum
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // subarray = arr[i....j]
            int sum = 0;

            // add all the elements of the subarray
            for(int k=i; k<j; k++){
                sum += arr[k];
            }
            maxi = std::max(sum, maxi);
        }
    }
    return maxi;
}

int main(){
    int arr[] = {-2,-3, 4, -1, -2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 9*4 / 4
    int maxSum = maxSubarraysum(arr, n);
    std::cout<<"The maximum subarray sum is: "<<maxSum<<std::endl;
    return 0;
}