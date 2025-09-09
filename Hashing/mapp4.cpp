// using map for number hashing

#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        std::cin>>arr[i];
    }

    // pre compute
    std::map<int, int> mpp;
    for(int i=0; i<n;i++){
        mpp[arr[i]]++;
    }
    //iterate in the map
    for(auto itr: mpp){
        std::cout<<itr.first << "->" <<itr.second<<std::endl;
    }

    int q;
    std::cin>>q;
    while(q--){
        int number;
        std::cin>>number;
        //fetching
        std::cout<<number<<"-> "<<mpp[number]<<std::endl;
    }
    return 0;
}