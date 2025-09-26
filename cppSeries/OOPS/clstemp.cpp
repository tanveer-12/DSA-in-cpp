// class templates
#include <iostream>

template <typename T>
struct Pair{
    T first{};
    T second{};
};

// here's a deduction guide for our Pair (required in cpp17 or older)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
template <typename T>
Pair(T, T) -> Pair<T>;

int main(){
    Pair<int> p1{5,6}; 
    std::cout<<p1.first<<" "<<p1.second;
    return 0;
}