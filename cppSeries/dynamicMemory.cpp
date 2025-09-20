#include <stdlib.h>
#include <stdio.h>
#include <iostream>


int main(){
    int *ptr = NULL;
    ptr = new int(10);
    if(!ptr){
        std::cout<<"allocation of memory failed";
        exit(0);
    }
    std::cout<<"value of *p: "<< *ptr <<std::endl;
    // free the value once it is used
    delete ptr;
    
    //allocate an array
    ptr = new int[3];
    ptr[2] = 12;
    ptr[1] = 22;
    ptr[0] = 11;

    std::cout<<"Array: ";
    for(int i=0; i<3; i++){
        std::cout<< ptr[i]<<" ";
    }
    delete[] ptr;
    return 0;
}