/*  IMPLEMENTING QUEUE USING STACK


making Enqueue() operation costly, Enqueue() in O(n)
Dequeue() in O(1)
by using two stacks
*/

#include <bits/stdc++.h>

class myQueue{
    std::stack<int> s1, s2;

public:
    // Enqueue(x):
    // While s1 is not empty, move all elements from s1 to s2.
    // Push x into s1.
    // Move everything back from s2 to s1.
    // This guarantees that the front of the queue is always on top of s1.
    void enqueue(int x){
        // move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // push the element x to s1
        s1.push(x);

        // push everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue():
    // If s1 is empty → queue is empty (underflow).
    // Otherwise, pop from s1.

    void dequeue(){
        if(s1.empty()){
            // queue underflow
            return;
        }
        s1.pop();
    }

    // front operation
    int front(){
        if(s1.empty()){
            // queue empty
            return -1;
        }
        return s1.top();
    }

    // size operation
    int size(){
        return s1.size();
    }
};

int main(){
    myQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front: " << q.front() << '\n';  
    std::cout << "Size: " << q.size() << '\n';    

    q.dequeue();              
    std::cout << "Front: " << q.front() << '\n';   
    std::cout << "Size: " << q.size() << '\n';    

    return 0;
}