/*
You are given a sorted array containing N integers and a number X, you 
have to find the occurrences of X in the given array.

TC - O(2*logN), We are basically using the binary search algorithm twice.
SC - O(1)
*/

#include <bits/stdc++.h>

class Solution{
public:
    int firstIndex(std::vector<int> &arr, int n, int k){
        int low = 0, high = n-1;
        int first = -1;
        while(low <=high){
            int mid = (low + high) /2;
            if(arr[mid] == k){
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }

    int lastIndex(std::vector<int> &arr, int n, int k){
        int low = 0, high = n-1;
        int last = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid] == k){
                last = mid;
                // move to the right
                low = mid + 1;
            }
            else if(arr[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return last;
    }

    int countOccurence(std::vector<int>& arr, int target){
        int n = arr.size();
        int first = firstIndex(arr, n, target);
        // if first index is -1, that means the element is not there
        if(first == -1)  return 0;
        int last = lastIndex(arr, n, target);
        int count = (last - first + 1);
        return count;
    }
};

int main(){
    std::vector<int> array = {2,8,8,8,8,8,11,13};
    int n = array.size();
    int target = 8;
    Solution obj;
    int count = obj.countOccurence(array, target);
    std::cout<<"The count of occurence of "<<target<<" is: "<<count;
    return 0;
}