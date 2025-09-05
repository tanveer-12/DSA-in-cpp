// lambda expressions capture clause

#include <iostream>
#include <vector>

void print(std::vector<int> v){
    for(auto itr: v) std::cout<<itr<<" ";
    std::cout<<std::endl;
}

int main(){
    std::vector<int> v1;
    std::vector<int> v2;

    //capture v1 and v2 by reference
    auto byRef = [&](int m){
        v1.push_back(m);
        v2.push_back(m);
    };

    //capture v1 and v2 by value
    auto byVal = [&v1,&v2](int m){
        v1.push_back(m);
        v2.push_back(m);
    };
    byRef(20);
    byVal(10);
    print(v1);
    print(v2);
    return 0;
}