// reversing an array using recursion with two ptr approach

#include <bits/stdc++.h>

void reverse(int l, int arr[], int r){
    // base case
    if(l >= r) return;
    std::swap(arr[l], arr[r]);
    reverse(l+1,arr,r-1);
}

int main(){
    int n;
    std::cout<<"Enter array size, n: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)std::cin>>arr[i];
    reverse(0, arr, n-1);
    std::cout<<"After reversing the array: ";
    for(int i=0; i<n; i++) std::cout<<arr[i]<<" ";
    return 0;
}