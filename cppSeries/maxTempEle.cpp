// using function template to find the maximum element
// in the array

#include <iostream>

template<typename T>
T arrMax(T arr[], int n){
    T res = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > res){
            res = arr[i];
        }
    }
    return res;
}

// another version with 
// Function Templates: Non-Type Parameters
template <typename T, int limit>
T arrMax1(T arr[], int n){
    if (n>limit){
        throw "Array size exceeds limit!";
    }
    T res = arr[0];
    for(int i=0; i< n;i++){
        if(arr[i] > res){
            res = arr[i];
        }
    }
    return res;
}

int main(){
    int arr1[] = {10, 40, 3};
    std::cout<<arrMax<int>(arr1, 3)<<" ";

    float arr2[] = {10.5, 3.5, 1.5, 30.5};
    std::cout<<arrMax<float>(arr2, 4)<<" ";

    // function template with Non-Type Parameter
    try{
        int arr[] = {10,30,21};
        std::cout<<arrMax1<int, 5>(arr, 3)<<std::endl;
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    int * ptr {new int}; // new int allocates 4 bytes in the heap
    return 0;
}