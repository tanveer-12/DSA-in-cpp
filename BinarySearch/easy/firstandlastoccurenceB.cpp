/*
Given a sorted array of N integers, write a program to find the index of the first and last occurrence 
of the target key. If the target is not found then return {-1,-1}.

USING ONLY PURE BINARY SEARCH

k = target
n = size of the array
TC - 2 x O(logN)
SC - O(1) 
*/

#include <bits/stdc++.h>

int firstOccurence(std::vector<int> &arr, int n, int x){
    int low =0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(std::vector<int> &arr, int n, int x){
    int low =0, high = n-1;
    int last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;   
}

std::pair<int, int> firstandlastoccurence(std::vector<int> &arr, int n, int k){
    int first = firstOccurence(arr, n, k);
    if (first == -1) return {-1,-1};    //becuz if first is not there, then that means that element is not there and we don;t have to find the last occurence too
    int last = lastOccurence(arr, n, k);
    return {first, last};
}

int main(){
    std::vector<int> array = {2,8,8,8,8,8,22,33};
    int n = array.size();
    int k = 8;  // target
    std::pair<int, int> result = firstandlastoccurence(array, n, k);
    std::cout<<"The first and last occurence indices are: {"<<result.first<<", "<<result.second<<"}";
    return 0;
}
