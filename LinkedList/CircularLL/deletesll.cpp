// delete operation in the circular singly linked list

#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data)
    : data{data},
    next{nullptr}
    {}
};

class CircularLL{
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

    void deleteatBeginning(){
        // if the list is empty
        if(head == NULL){
            std::cout<<"List is empty";
            return;
        }
        // if there is only one circular node, that is head node
        if(head->next == head){
            delete head;
            head = nullptr;
        }
        Node* temp = head;
        Node* last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;  // head pointing to the new head
        last->next = head;  // last node pointing to the new head now
        delete temp;
    }
    
    // deleting the end node
    void deleteatEnd(){
        // if the list is empty
        if(head==NULL){
            std::cout<<"List is empty";
            return;
        }
        // if only one node in the ll
        if(head->next == head){
            delete head;
            head = nullptr;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while(temp->next != head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    // deleting the kth node
    void deleteatK(int k){
        // list is empty
        if(head==NULL){
            std::cout<<"List is empty";
            return;
        }
        // if there is only one node, that is beginning node
        if(k==1){
            deleteatBeginning();
            return;
        }
        //  deleting the kth or end node
        Node* temp = head;
        Node* prev = nullptr;
        int cnt = 0;
        while(temp->next != head){
            cnt++;
            if(cnt == k){break;}
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
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
    cll.insertBeforeHead(47);
    cll.insertBeforeHead(81);
    cll.insertBeforeHead(62);
    cll.display();
    std::cout<<std::endl;
    cll.deleteatBeginning();
    cll.display();
    std::cout<<std::endl;
    cll.deleteatK(3);
    cll.display();
    std::cout<<std::endl;
    cll.deleteatEnd();
    cll.display();
    return 0;
}