// for each loop
#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec = {1,2,3,4,5};

    //by value
    std::cout<<"Iterating by value: "<<std::endl;
    for(auto itr:vec){
        std::cout<<itr<<" ";
    }
    std::cout<<std::endl;

    //by reference
    std::cout<<"Iterating by reference: "<<std::endl;
    for(auto &itr:vec){
        std::cout<<itr<<" ";
    }
    std::cout<<std::endl;
    
    // trying break and continue
    for(int i=0; i<5;i++){
        if(i==2) break;
        std::cout<<"HI"<<std::endl;
    }
    for(int i=0; i<5;i++){
        if(i==2) continue;
        std::cout<<i<<std::endl;
    }
    return 0;
}