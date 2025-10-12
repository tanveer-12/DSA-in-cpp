// inserting a node in the singly LL at specific positions

#include <iostream>

class Node{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    : data{data},
    next{nullptr}
    {}
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList()
    : head{nullptr}
    {}

    // Inserting at the beginning of the list
    void insertBegin(int data){
        Node *newnode = new Node(data);
        newnode->next = head;   //
        head = newnode;         // head now points to the new node
    }

    // Inserting the node after the tail node ( at the ending)
    void insertEnd(int data){
        Node* newnode = new Node(data);
        if(!head){      // if list is empty, our newnode becomes head
            head = newnode;
            return;
        }
        Node* temp = head;      // to traverse and not loose head, we keep another pointer which points to the head itself
        while(temp->next){
            temp = temp->next;     // traverse until the last node
        }
        temp->next = newnode;
    }

    // Inserting the node at a position
    void insertPosition(int data, int position){
        // we will traverse the node until (position-1)
        if(position < 1){
            std::cout<<"Invalid position";
            return;
        }
        if(position == 1){         // position is beginning of the LL
            insertBegin(data);
            return;
        }
        Node* temp = head;
        for(int i=0; i<position-1 && temp;++i){
            temp = temp->next;
        }
        if(!temp){
            std::cout<<"Position out of range";
            return;
        }
        Node* newnode = new Node(data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    // ------------------------
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main(){
    LinkedList list;

    list.insertBegin(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertPosition(15, 2);

    std::cout << "List after insertions: ";
    list.display();

    return 0;
}