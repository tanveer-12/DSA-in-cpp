// printing any one subsequence whose sum is k

#include <bits/stdc++.h>

bool one_subseq(int ind,std::vector<int> &ds, int arr[], int n, int s, int sum){
    // base case
    if(ind == n){
        // condition satisfied
        if(s == sum){
            for(auto itr:ds){
                std::cout<<itr<<" ";
            }
            return true;
        }
        // condition not satisfied
        else 
            return false;
    }
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(one_subseq(ind+1, ds, arr, n, s, sum)==true){
        return true;
    }
    s-= arr[ind];
    ds.pop_back();
    // not pick
    if(one_subseq(ind+1, ds, arr, n,s,sum)==true){
        return true;
    }
    // if none of the conditions returned a subsequence then return false
    return false;
}

int main(){
    int arr[]={1,2,2};
    int n=3, sum=2;
    std::vector<int> ds;
    one_subseq(0, ds, arr, n, 0,sum);
    return 0;
}