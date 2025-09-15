// leetcode 189 - Rotate the array to the right by  
// k steps, where k is non-negative

#include <bits/stdc++.h>

// brute force
void rotate(std::vector<int> & nums, int k){
    int n = nums.size();
    k = k % n;
    int temp[k];
    // putting elements into temp
    for(int i=0; i<k;i++){
        temp[i] = nums[i];
    }
    //shifting elements to left by k places
    for(int i=k; i<n; i++){
        nums[i-k] = nums[i];
    }
    // putting elements from temp at the back
    for(int i=n-k; i<n; i++){
        nums[i] = temp[i-(n-k)];
    }
}

// optimzed
void reverse(std::vector<int> &nums, int start, int end){
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(std::vector<int> &v, int k){
    int n = v.size();
    k = k % n;
    reverse(v, 0, k-1);
    reverse(v, k, n-1);
    reverse(v, 0, n-1);
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<"Enter array elements: ";
    std::vector<int> arr(n);
    for(int i=0; i<n;i++){
        std::cin>>arr[i];
    }
    int k;
    std::cout<<"Rotate array by how many steps: ";
    std::cin>>k;
    rotate(arr, k);
    std::cout<<"Array rotated by "<<k<<" steps: \n";
    for(auto itr: arr){
        std::cout<<itr<<" "; 
    }
    leftRotate(arr, k);
    std::cout<<"Array rotated by "<<k<<" steps: \n";
    for(auto itr: arr){
        std::cout<<itr<<" "; 
    }
    return 0;
}