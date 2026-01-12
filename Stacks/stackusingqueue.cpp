/*  STACK USING QUEUES

SINGLE QUEUE IMPLEMENTATION 
PUSH IN O(n)
POP IN O(1)
*/

#include <bits/stdc++.h>

class myStack{
    std::queue<int> q;
public:
    // push operation
    void push(int x){
        q.push(x);
        int qsize = q.size();
        for(int i=0; i < qsize-1; i++){
            // moving the current top element to the back of the queue
            q.push(q.front());
            // then deleting the current top as the element already got pushed to the back
            // so has to remove it from the front
            q.pop();
        }
    }

    // pop operation
    void pop(){
        if(!q.empty()){
            q.pop();
        }
    }

    // return top element
    int top(){
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    // return current size
    int size() {
        return q.size();
    }
};

void printStack(myStack s){
    std::cout<<"Stack elements (top to bottom): ";
    while(s.size() != 0){
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<std::endl;
}

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    printStack(st);
    std::cout <<"top element: "<< st.top() << std::endl;
    st.pop();
    std::cout << "top element after pop: "<<st.top() << std::endl;
    st.push(6);
    std::cout <<"top element: "<< st.top() << std::endl;
    return 0;
}