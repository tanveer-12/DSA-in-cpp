#include <iostream>

int main(){
    int n = 10;
    int *p = &n;    //single ptr
    int **p2 = &p;  //double ptr
    int ***p3 = &p2;    //triple ptr
    std::cout<<&n<<std::endl;
    std::cout<<p<<std::endl;
    std::cout<<&p<<std::endl;
    std::cout<<p2<<std::endl;
    std::cout<<&p2<<std::endl;
    std::cout<<p3<<std::endl;
    //value modification
    // to make n=10 to n=15
    *p = *p + 5;
    std::cout<<n<<"\n";
    **p2 = **p2 + 5;    //makes n=15 to n=15+5 => 20
    std::cout<<n<<std::endl;
    ***p3 = ***p3 - 5;  //makes n=20 to n=20-5 => 15
    std::cout<<n;
    return 0;    
}