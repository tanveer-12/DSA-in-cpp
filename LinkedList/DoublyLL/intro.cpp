// generating a doubly LL from an array
#include <iostream>
#include <vector>

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    : data{data},
    next{nullptr},
    prev{nullptr}
    {}

    Node(int data, Node* next, Node* prev)
    : data{data},
    next{next},
    prev{prev}
    {}
};


Node* arraytoDLL(std::vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    std::cout<<"NULL";
}

int main(){
    std::vector<int> arr = {2,3,1,4};
    Node* head = arraytoDLL(arr);
    display(head);
    return 0;
}