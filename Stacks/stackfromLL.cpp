/*  IMPLEMENTING STACK USING LINKED LISTS

TC - O(1) for push, pop, peek operations
SC - O(1)
*/

#include <bits/stdc++.h>

class Node{
public: 
    int data;
    Node *next;

    // constructor
    Node(int x)
    : data{x},
    next{NULL}{}
};

class myStack{
    Node *top;
    int size;
public:
    myStack()
    : top{NULL},
    size{0}
    {}

    // push operation
    // TC - O(1), SC - O(1)
    void push(int x){
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    // pop operation
    void pop(){
        if(top == NULL){
            std::cout<<"Stack is empty";
            return;
        }
        Node *temp = top;
        top = top->next;
        size--;
        delete temp;
    }

    // peek operation
    int peek(){
        if(top == NULL){
            std::cout<<"Stack is empty";
            return -1;
        }
        return top->data;
    }

    // size of stack
    int sizeStack(){
        return size;
    }

    // displaying the elements of the stack
    void display(){
        Node *current = top;
        if(current == nullptr){
            std::cout<<"stack is empty";
            return;
        }
        std::cout<<"Elements in the stack (top to bottom): ";
        while(current != nullptr){
            std::cout<<current->data<<" ";
            current = current->next;
        }
        std::cout<<std::endl;
    }
};

int main(){
    myStack st;
    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); 
    st.push(5);
    st.display();
    // popping one element
    st.pop();
    std::cout<<"Top element after pop: "<<st.peek()<<std::endl;
    st.display();
    std::cout<<"size of stack is: "<<st.sizeStack();
    return 0;
}