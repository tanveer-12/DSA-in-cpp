/*
Given distinct sorted order, search for the index of target value x
If found return that index, otherwise, determine the index where it would
be inserted in array while maintaining sorted order
TC - O(logN)
SC - O(1)

*/

#include <iostream>
#include <vector>

int searchInsert(std::vector<int> &arr, int x){
    int n = arr.size(), low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low + high) /2 ;
        if(arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    std::vector<int> array = {1,2,4,7};
    int y = 6;
    int result = searchInsert(array, y);
    std::cout<<"The index is: "<<result;
    return 0;
}