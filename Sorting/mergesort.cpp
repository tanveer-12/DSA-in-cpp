// divide and merge the array
// playing around with indexes and recursion because
// we are not creating multiple arrays in division

#include <bits/stdc++.h>

void merge(std::vector<int> &arr, int low, int mid, int high);
void mergesort(std::vector<int> &arr, int low, int high){
    // base case 
    if(low >= high) return;

    int mid = low + (high-low)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

//merges two subarrays of arr[]
// first subarray is arr[left...mid]
// second subarray is arr[mid+1...high]
void merge(std::vector<int> &arr, int low, int mid, int high){
    std::vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //copying the remaining elements of left
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    // copying the remaining elements of right
    // if there are any
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<= high; i++){
        arr[i] = temp[i-low];
    }
}

int main(){
    int n, low, high;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i){
        std::cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int element: arr){
        std::cout<<element<<" ";
    }
    return 0;
}