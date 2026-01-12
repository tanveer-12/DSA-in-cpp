/*      STACK IMPLEMENTATION USING ARRAYS
    LIFO - LAST IN FIRST OUT
*/

#include <bits/stdc++.h>

class myStack{
    // array to store elements
    int *stack;
    // maximum size of stack
    int capacity;
    // index of top element
    int top;
public:
    // constructor
    myStack(int cap)
    : capacity{cap},
    top{-1} // top = -1 to indicate an empty stack.
    {
        stack = new int[capacity];
    }

    // push operation, TC - O(1), SC - O(1)
    // If the stack is full (top == capacity-1) , then Stack Overflows and we cannot insert the element to the stack.
    // Otherwise, we increment the value of top by 1 (top = top + 1) and 
    // the new value is inserted at top position 
    void push(int x){
        if(top == capacity - 1){
            std::cout<<"Stack overflows. cannot insert element "<<x;
            return;
        }
        stack[++top] = x;   // first increment top and then insert x at the new top index
    }

    // if we want to return the popped element
    // If the stack is empty (top == -1), then Stack Underflows and we cannot remove any element from the stack.
    // Otherwise, we store the value at top, decrement the value of top by 1 (top = top – 1) 
    // and return the stored top value.
    int pop(){  // TC - O(1), SC - O(1)
        if(top == -1){
            std::cout<<"Stack is empty";
            return -1;
        }
        return stack[top--];    // first return the stack[top] and then top--
    }

    // return the top or peek element
    // TC - O(1), SC - O(1)
    int peek() {
        if (top == -1) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return stack[top];
    }
};

int main() {
    myStack st(4);

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // checking top element
    std::cout << "Top element: " << st.peek() << "\n";

    // popping one element
    std::cout << "Popped: " << st.pop() << "\n";

    // checking top element
    std::cout << "Top element after pop: " << st.peek() << "\n";
    return 0;
}