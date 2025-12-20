/*
Given a sorted array of N integers, write a program to find the index of the first and last occurrence 
of the target key. If the target is not found then return {-1,-1}.

k = target
n = size of the array
TC - 2 x O(logN)
SC - O(1)  
*/

#include <iostream>
#include <bits/stdc++.h>

int lowerBound(std::vector<int> &arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        //maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else{
            low = mid+1;    //look for right
        }
    }
    return ans;
}

int upperBound(std::vector<int> &arr, int n, int x){
    int low=0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low + high)/2;
        //maybe an answer
        if(arr[mid] > x){
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else{
            low = mid + 1; //look for right
        }
    }
    return ans;
}

std::pair<int, int> firstandlastPosition(std::vector<int>& arr, int n, int k){
    int lb = lowerBound(arr, n, k);
    // edge cases
    if(lb == n || arr[lb] != k){
        return {-1, -1};
    }
    else{
        return {lb, upperBound(arr, n,k) - 1};
    }
}

int main(){
    std::vector<int> array = {2,4,6,8,8,8,11,13,15,18,19};
    std::pair<int, int> result = firstandlastPosition(array, 11, 8);
    std::cout<<"The first and last occurence indices are: {"<<result.first<<", "<<result.second<<"}";
    return 0;
}