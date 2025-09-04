#include <bits/stdc++.h>

int cnt=0;

void f(){
    if(cnt ==4) return;
    std::cout<<cnt<<std::endl;
    cnt++;
    f();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    f();
    return 0;
}