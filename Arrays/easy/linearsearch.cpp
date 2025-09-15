// Linear Search a number through an array and return
// its index if found, otherwise return -1

#include <bits/stdc++.h>

int linearSearch(int arr[],int n, int k){
    for(int i=0; i<n;i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<"Enter num you want to search: ";
    int k;
    std::cin>>k;
    int result = linearSearch(arr,n, k);
    std::cout<<"Index of "<<k<<" is: "<<result;
    return 0;
}