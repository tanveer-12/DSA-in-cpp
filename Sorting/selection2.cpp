// in selectionsort.cpp, we brought the smallest element to 
// the first position, 
// but in this, we will bring the largest element to the back

#include <bits/stdc++.h>

void selection(int arr[], int n){
    for(int i=n-1; i<=0;i++){
        int index =i;
        for(int j=n-2;j>0;j++){
            if(arr[j]>arr[index]){
                index=j;
            }
        }
        std::swap(arr[i], arr[index]);
    }
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        std::cin>>arr[i];
    }
    for(int i=0; i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    selection(arr, n);
    for(int i=0; i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}