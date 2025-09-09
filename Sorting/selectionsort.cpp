// from coder army playlist video = 19
// SELECTION SORT
/*
1. finding the smallest element and swap it with the first 
element. this way we get the smallest element at its correct
position.
2. then we find the smallest among the remaining elements ( or
second smallest) and swap it with the second element
3. we keep doing this until we get all elements moved to 
the correct positions
Time complexity: O(n)
Space complexity: O(n)
*/

#include <bits/stdc++.h>

void selectionsort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j=i+1; j<n;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        std::swap(arr[i], arr[index]);
    }
}

int main(){
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<"Before selection sort: \n";
    for(int i=0; i<6;i++){
        std::cout<<arr[i]<<" ";
    }
    selectionsort(arr,n);
    std::cout<<"\nAfter selection sort: \n";
    for(int i=0; i<6;i++){
        std::cout<<arr[i]<<" ";
    }
}
