// check if the array is sorted

#include <bits/stdc++.h>

bool chkSorted(std::vector<int> & arr, int n){
    for(int i =1; i<n;i++){
        if(arr[i] >= arr[i-1]){
            
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    bool res = chkSorted(arr, n);
    if(res){
        std::cout<<"Array is sorted";
    }
    else{
        std::cout<<"Array is not sorted";
    }
    return 0;
}