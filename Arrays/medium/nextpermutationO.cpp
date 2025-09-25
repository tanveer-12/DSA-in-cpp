// find the next permutation - L27
// OPTIMAL SOLUTION
// TC -> O(3N) = finding breakpoint + finding next greater
// element + reversal at the end of the program
// SC -> O(1) =  no extra space required

/*
The steps are the following:

- Find the break-point, i: Break-point means the first index i from the back of the 
given array where arr[i] becomes smaller than arr[i+1].
    For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be 
    index 1(0-based indexing). Here from the back of the array, index 1 is the 
    first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
    To find the break-point, using a loop we will traverse the array backward and 
    store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
- If such a break-point does not exist i.e. if the array is sorted in decreasing 
    order, the given permutation is the last one in the sorted order of all 
    possible permutations. So, the next permutation must be the first i.e. the 
    permutation in increasing order.
    So, in this case, we will reverse the whole array and will return it as our 
    answer.
- If a break-point exists:
        Find the smallest number i.e. > arr[i] and in the right half of index 
        i(i.e. from index i+1 to n-1) and swap it with arr[i].
        Reverse the entire right half(i.e. from index i+1 to n-1) of index i. 
        And finally, return the array.
*/

#include <bits/stdc++.h>

std::vector<int> nextPerm(std::vector<int> &vec){
    int n = vec.size();

    // step 1: finding the breakpoint
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(vec[i] < vec[i+1]){
            ind = i;
            break;
        }
    }
    // if breakpoint does not exist
    if(ind == -1){
        std::reverse(vec.begin(), vec.end());
        return vec;
    }

    // step 2: finding the next greater element and then swap it with vec[ind]
    for(int i=n-1; i> ind; i--){
        if(vec[i] > vec[ind]){
            std::swap(vec[i], vec[ind]);
            break;
        }
    }
    // step 3: reversing the right portion 
    std::reverse(vec.begin() + ind + 1, vec.end());
    return vec;
}

int main(){
    std::vector<int> A = {2,1,5,4,3,0,0};
    std::vector<int> ans = nextPerm(A);
    std::cout<<"The next permutation is: [";
    for(auto itr: ans){
        std::cout<<itr<<" ";
    }
    std::cout<<"]";
    return 0;
}