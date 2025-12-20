// Binary search intro code - Iterative and recursive - Lecture 1
// returning the index of element 13 if found in array

#include <iostream>

int binaryIterative(int arr[], int n, int target){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]){
            // target lies in the right portion, so left portion gets eliminated
            low = mid+1;
        }
        else{ // target lies in the left portion, so right portion gets eliminated
            high = mid -1;
        }
    }
    return -1;
}

int binaryRecursive(int arr[], int low, int high, int target){
    // base case
    if( low > high){return -1;}
    int mid = (low+high)/2;
    if(arr[mid] == target){
        return mid;
    }
    else if(target > arr[mid]){
        return binaryRecursive(arr, mid+1, high, target);
    }
    return binaryRecursive(arr, low, mid-1, target);
}

int main(){
    return 0;
}