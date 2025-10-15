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

    // inserting at the beginning of the CSLL
    void insertBeforeHead(int val){
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

    // inserting at the end of the CSLL
    void insertatEnd(int val){

    }

    // inserting a node at a Kth position
    void insertatK(int val, int k){
        // if the k==1, that is head position
        if(k==1){
            insertBeforeHead(val);
            return;
        }
        Node* temp = head;
        int cnt =0;
        while(temp->next != head){
            cnt++;
            if(cnt == k-1){break;}
            temp = temp->next;
        }
        if(temp->next == head && cnt<k){
            std::cout<<"Position is out of range\n";
            return;
        }
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
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
    cll.insertBeforeHead(12);
    cll.insertBeforeHead(3);
    cll.insertBeforeHead(4);
    cll.insertBeforeHead(8);
    cll.insertBeforeHead(9);
    cll.insertBeforeHead(31);
    cll.insertBeforeHead(41);
    cll.display();
    std::cout<<std::endl;
    cll.insertatK(33, 9);
    cll.display();
    return 0;
}