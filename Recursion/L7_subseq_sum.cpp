// printing the subsequences whose sum is K
/*
Input : arr->{1,2,1} and sum =2
then resulting subsequences should be
Output: {1,1}, {2}
*/

#include <bits/stdc++.h>

void subseq_sum(int ind, std::vector<int> &ds,int arr[] ,int s, int sum,int n){
    // base case
    if(ind == n){
        if(s == sum){
            for(auto itr: ds){
                std::cout <<itr<< " ";
            }
            std::cout<<std::endl;
        }
        return;
    }
    // when we pick the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    subseq_sum(ind+1, ds, arr, s, sum, n);
    
    s -= arr[ind];
    ds.pop_back();
    // not pick condition
    subseq_sum(ind+1, ds, arr, s, sum, n);
}

int main(){
    int arr[] = {1,2,1};
    int n =3, sum=2;
    std::vector<int> ds;
    subseq_sum(0, ds,arr,0,sum,n);
    return 0;
}