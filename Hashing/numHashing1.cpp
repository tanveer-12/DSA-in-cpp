// introduction about number hashing -> video 13 

#include <bits/stdc++.h>

int main(){
    int n;
    std::cout<<"Enter size of array: ";
    std::cin>>n;
    int arr[n];
    std::cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    // pre computing the hashed values in hash arr
    int hash[13]={0};   // here taken 13 because we know the input will have max 12 so taken 12+1 size to include the 12th index
    for(int i=0; i<n;i++){
        hash[arr[i]] += 1;
    }

    // inputs : which numbers to loopup
    int q;
    std::cout<<"How many numbers you want to loop up: ";
    std::cin>>q;
    std::cout<<"Enter the numbers which you want count for: ";
    while(q--){
        int number;
        std::cin>>number;
        //fetching
        std::cout<<number<<" -> "<<hash[number]<<std::endl;
    }
}
