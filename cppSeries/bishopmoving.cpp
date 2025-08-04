/*
Given the position of a Bishop (A, B) on an 8 * 8 chessboard.
Your task is to count the total number of squares that can be visited 
by the Bishop in one move.
The position of the Bishop is denoted using row and column number of the chessboard.
*/

#include <iostream>
#include <algorithm>

int bishopTotal(int a, int b){
    int total = 0;
    total = total + std::min(8-a, 8-b);
    total += std::min(8-a, b-1);
    total += std::min(a-1, 8-b);
    total += std::min(a-1, b-1);
    return total;
}

int main(){
    int a,b;
    std::cout<<"Position for Bishop in x and y: ";
    std::cin>>a>>b;
    std::cout<<bishopTotal(a,b)<<std::endl;
    return 0;
}