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
    Node* last = nullptr;
    Node* curr = head;
    while(curr!= NULL){
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
    }
    return last->back;  // updated head
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