// find the largest element in the array

#include <bits/stdc++.h>

// brute method with TC-O(n)
int largestbrute(int arr[], int n){
    // sorting the array first
    // then returning the arr[n-1] element which will be the largest
}

// better solution with TC-O(2n)
int largestOptimal(int arr[], int n){
    int largest = arr[0];
    for(int i=0; i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}


int main(){
    int arr[6] = {31, 51, 6, 2, 11, 90};
    int result = largestbrute(arr, 6);
    std::cout<<"Largest element is: "<<result;
    return 0;
}