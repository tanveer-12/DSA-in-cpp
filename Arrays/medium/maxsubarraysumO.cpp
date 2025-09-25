// Maximum Subarray Sum in an Array
// OPTIMAL SOLUTION : KADANE's ALGORITHM
// The intuition of the algorithm is not to consider the 
// subarray as a part of the answer if its sum is less 
// than 0. A subarray with a sum less than 0 will always 
// reduce our answer and so this type of subarray cannot 
// be a part of the subarray with maximum sum.
// - We will run a loop(say i) to iterate the given array.
// - Now, while iterating we will add the elements to the 
// sum variable and consider the maximum one.
// - If at any point the sum becomes negative we will 
// set the sum to 0 as we are not going to consider it as
// a part of our answer.
// TC - O(N) = using one loop iteration
// SC - O(1) = not using any extra space

#include <bits/stdc++.h>

long long maxSubarraysum(int arr[], int n){
    long long maxi = LONG_MIN;     //maximum sum
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        // if sum<0, discard the sum calculated
        if(sum <0){
            sum = 0;
        }
        // to consider the sum of empty subarray
        // edge case -> might be given
        if(maxi < 0){
            maxi = 0;
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