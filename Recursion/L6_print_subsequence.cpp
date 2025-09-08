// Pattern: Recursion/Backtracking

#include <bits/stdc++.h>

void print_sub(int index,std::vector<int> &ds ,int arr[], int n){
    // base case
    if(index >= n){
        //printing the data structure
        for(auto itr: ds){
            std::cout <<itr<<" ";
        }
        if(ds.size()==0){
            std::cout<<"{}";
        }
        std::cout<<std::endl;
        return;
    }
    //take or pick the particular index into the subsequence
    ds.push_back(arr[index]);
    print_sub(index +1, ds, arr,n);
    ds.pop_back(); // because removing the last element always

    // not pick, or not take
    print_sub(index +1, ds, arr, n);
}

int main(){
    int arr[] = {3,1,2};
    int n =3;
    std::vector<int> ds;
    print_sub(0, ds, arr, n);
    return 0;
}