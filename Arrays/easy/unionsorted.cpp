// union of two sorted arrays
// union contains unique elements in the sorted manner
// so we consider using set DS to maintain the uniqueness
// and the sorted order

#include <bits/stdc++.h>
// I am taking references to the original arrays, so 
// either run the brute or optimal approch,
// do not run them together since one of them could alter
// the original array and then that modified array will be 
// passed to the other function

// Taking SET DS
std::vector<int> unionBrute(std::vector<int> &a1, std::vector<int> &a2){
    int n1 = a1.size();
    int n2 = a2.size();
    std::set<int> st;
    for(int i=0; i<n1; i++){
        st.insert(a1[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(a2[i]);
    }
    // declaring union vector
    std::vector<int> temp(st.size());
    int i=0;
    for(auto itr: st){
        temp[i++] = itr;    // or temp.push_back(itr);
    }
    return temp;
}

// using TWO POINTERS APPROACH
std::vector<int> unionOptimal(std::vector<int> &a1, std::vector<int> &a2){
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0, j=0;
    std::vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a1[i] <= a2[j]){
            // if union is initially empty, enter the element that is why
            // unionArr.size()==0, so push_back(a1[i])
            if(unionArr.size() == 0 || unionArr.back() != a1[i]){
                unionArr.push_back(a1[i]);
            }
            i++;
        }
        else{
            // if a1[i] >= a2[j], put the a2[j] into the union
            // since we want the sorted array, so putting the smallest
            // of a1 and a2
            if(unionArr.size() == 0 || unionArr.back() != a2[j]){
                unionArr.push_back(a2[j]);
            }
            j++;
        }
    }
    // if a1 array is exhausted
    while(j<n2){
        if(unionArr.size() == 0 || unionArr.back() != a2[j]){
            unionArr.push_back(a2[j]);
        }
        j++;
    }
    // if a2 array is exhausted
    while(i<n1){
        if(unionArr.size() == 0 || unionArr.back() != a1[i]){
            unionArr.push_back(a1[i]);
        }
        i++;
    }
    return unionArr;
}

int main(){
    int n1, n2;
    std::cout<<"Enter array sizes n1 and n2: ";
    std::cin>>n1>>n2;
    std::vector<int> arr1(n1), arr2(n2);
    std::cout<<"Enter array 1 elements in sorted order: ";
    for(int i=0; i<n1; i++){
        std::cin>>arr1[i];
    }
    std::cout<<"Enter array 2 elements in sorted order: ";
    for(int i=0; i<n2; i++){
        std::cin>>arr2[i];
    }
    std::vector<int> result = unionBrute(arr1, arr2);
    std::vector<int> result2 = unionOptimal(arr1, arr2);
    for(auto itr: result2){
        std::cout<<itr<<" ";
    }
    return 0;
}