// - Left rotate an array by one place

#include <bits/stdc++.h>

void rotateArray(std::vector<int> &v){
    int n = v.size();
    int temp = v[0];    // storing the first elem in temp
    for(int i =1; i<n;i++){
        v[i-1] = v[i];
    }
    v[n-1] = temp;
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<"Enter array elements: ";
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    rotateArray(arr);
    std::cout<<"After rotation by one place\n";
    for(auto itr: arr){
        std::cout<<itr<<" ";
    }
    return 0;
}