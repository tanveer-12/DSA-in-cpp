// Reversing array using recursion
// using only one pointer
#include <bits/stdc++.h>

void reverse(int i, int arr[], int n){
    // base case
    if(i >= n/2) return;
    std::swap(arr[i], arr[n-i-1]);
    reverse(i+1, arr, n);
}

int main(){
    int n;
    std::cout<<"Enter n for array: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements: ";
    for(int i=0; i<n;i++) std::cin>>arr[i];
    reverse(0, arr, n);
    std::cout<<"After reversing the array: ";
    for(int i=0; i<n;i++) std::cout<<arr[i]<<" ";
    return 0;
}