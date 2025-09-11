// divide and conquer method

#include <bits/stdc++.h>

int partition(std::vector<int> &arr, int low, int high);
void qs(std::vector<int> &arr, int low, int high);

int main(){
    int n;
    std::cout<<"Enter array size: ";
    std::cin>>n;
    std::cout<<"Enter array elements (space): ";
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i){
        std::cin>>arr[i];
    }
    qs(arr,0,arr.size()-1);
    std::cout<<"After quick sort: \n";
    for(int element: arr){
        std::cout<<element<<" ";
    }
}

void qs(std::vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    }
}

int partition(std::vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i=low, j= high;
    while( i< j){
        while(arr[i] <= pivot && i<= high-1){
            i++;
        }
        while(arr[j] >  pivot && j >= low +1){
            j--;
        }
        if(i<j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}