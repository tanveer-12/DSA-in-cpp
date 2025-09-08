// count the subsequences whose sum is k

#include <bits/stdc++.h>

int count_seq(int ind,int arr[], int n, int s, int sum){
    //base case
    if(ind == n){
        if(s == sum){
           return 1; 
        }
        else{
            return 0;
        }
    }
    
    s += arr[ind];
    int l = count_seq(ind+1,arr,n,s,sum);
    s-= arr[ind];
    
    int r = count_seq(ind+1,arr,n,s,sum);
    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int n=3, sum=2;
    std::cout << count_seq(0,arr, n, 0, sum);
    return 0;
}