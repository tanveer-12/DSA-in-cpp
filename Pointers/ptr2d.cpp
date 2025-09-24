// creating and deleting 2d array using dynamic memory allocation

#include <iostream>

int main(){
    int n, m;
    std::cout<<"Enter num of rows, n: ";
    std::cin>>n;
    std::cout<<"Enter num of cols, m: ";
    std::cin>>m;
    //creating 2d array
    // which is nothing but actually
    // multiple 1d arrays in a loop
    int **ptr = new int *[n];
    for(int i=0; i<n; i++){
        ptr[i] = new int [m];
    }
    // storing values in the 2d array
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin>>ptr[i][j];
        }
    }
    // deleting the memory occupied
    // first deleting all the arrays we created
    // using pointers 
    for(int i=0; i<n; i++){
        delete[] ptr[i];
    }
    // now delete the ptr pointer pointing to an int array
    delete[] ptr;
    return 0;
}