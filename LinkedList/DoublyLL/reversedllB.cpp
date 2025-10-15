// Reverse a DLL
// BRUTE FORCE APPROACH

#include <iostream>
#include <vector>
#include <stack>

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data)
    :data {data},
    next {nullptr},
    back {nullptr}
    {}

    Node(int data, Node* next, Node* back)
    : data {data},
    next {next},
    back {back}
    {}
};

Node* reversedll(Node* head){
    // if head is null or there is only one element
    if(head==NULL || head->next == NULL){
        return head;
    }
    std::stack<int> st;
    Node* temp = head;
    while(temp!= NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    // reinitializes the temp to head
    temp = head;

    // second iteration to replace the values in the dll, with the stack data
    while(temp!= NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* arrtodll(std::vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void print(Node* head){
    while(head!= nullptr){
        std::cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    std::vector<int> array = {3,5,7,9,2};
    Node* head = arrtodll(array);
    std::cout<<"Initial Doubly Linked list: ";
    print(head);
    std::cout<<"\nDoubly Linked List after reversing: ";
    head = reversedll(head);
    print(head);
    return 0;
}