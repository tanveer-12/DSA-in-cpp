// Intersection of two sorted arrays

#include <bits/stdc++.h>

// brute force approach
// using a visited array
std::vector<int> interBrute(std::vector<int> & a, std::vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    std::vector<int> visited(n2,0);
    std::vector<int> ansArr;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a[i] == b[j] && visited[j] == 0){
                ansArr.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return ansArr;
}

// OPTIMIZED : TWO POINTER APPROACH
std::vector<int> interOptimal(std::vector<int> & a, std::vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0, j=0;
    std::vector<int> ansArr;
    while(i<n1 && j < n2){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else{   // when a[i] == b[j]
            ansArr.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ansArr;
}

int main(){
    std::vector<int> arr1 = {1,2,2,3,3,4,5,6};
    std::vector<int> arr2 = {2,3,3,5,6,6,7};
    std::vector<int> result = interBrute(arr1, arr2);
    std::vector<int> result2 = interOptimal(arr1, arr2);
    for(auto itr: result2){
        std::cout<<itr<< " ";
    }
    return 0;
}