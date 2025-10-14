// insertion operation in Circular Singly LL 
#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data)
    :data{data},
    next{nullptr}
    {}
};

class CircularLL{
private:
    Node* head;
public:
    CircularLL()
    : head{nullptr}
    {}

    void InsertBeforeHead(int val){
        // if the CLL is empty
        if(head==NULL){
            Node* temp = new Node(val);
            head = temp;
            temp->next = head;
        }
        // if it is not empty, our newnode becomes the new head of the CLL
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node* newnode = new Node(val);
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    void display(){
        Node* temp = head;
        while(temp->next != head){
            std::cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        std::cout<<"|\n";
        std::cout<<"->"<<head->data;
    }
};

int main(){
    CircularLL cll;
    cll.InsertBeforeHead(12);
    cll.InsertBeforeHead(3);
    cll.display();
}