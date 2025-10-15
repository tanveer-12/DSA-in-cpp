// Inserting nodes in the Doubly Circular LL
#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node(int data)
    : data{data}
    , next {nullptr}
    , back {nullptr}
    {}

    Node(int data, Node* next, Node* back)
    : data {data},
    next {next},
    back {back}
    {}
};

class DoublyCLL{
Node* head;
public:
    DoublyCLL()
    : head {nullptr}
    {}

    // Destructor to free memory
    ~DoublyCLL() {
        if (head == nullptr) {
            return;
        }
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    //----- inserting node at the beginning ------
    void insertatBeginning(int val){
        // if the list is empty
        if(head == NULL){
            Node* temp = new Node(val);
            head = temp;
            temp->next = head;
            temp->back = head;
        }
        Node* last = head->back;
        Node* newnode = new Node(val, head, last);
        last->next = newnode;
        head->back = newnode;
        head = newnode;
    }

    // ----- inserting the node at the end -------
    void insertatEnd(int val){
        // if the list is empty
        if(head == NULL){
            Node* temp = new Node(val);
            head = temp;
            temp->next = head;
            temp->back = head;
        }
        Node* last = head->back;
        Node* newnode = new Node(val, head, last);
        last->next = newnode;
        head->back = newnode;
    }

    //--------insert at Kth position -------
    void insertatK(int val, int k){
        // if the list is empty
        Node* newnode = new Node(val);
        if(head==NULL){
            if(k != 1){
                std::cout<<"Invalid position for an empty list";
                delete newnode;
                return;
            }
            head = newnode;
            head->next = newnode;
            head->back = newnode;
            return;
        }
        // case 1: if there is only one node, and the k=1, that is insert at head position
        if(k==1){
            insertatBeginning(val);
            return;
        }
        // case2: insertion at a specific position
        Node* temp = head;
        int cnt = 0;
        while(temp->next != head){
            cnt++;
            if(cnt == k-1){break;}
            temp = temp->next;
        }

        // check if the position is valid
        if(cnt < k && temp->next == head){
            std::cout<<"Invalid position. K is out of bounds\n";
            delete newnode;
            return;
        }

        newnode->next = temp->next;
        newnode->back = temp;
        temp->next->back = newnode;
        temp->next = newnode;
    }

    // -------- Display function ----------
    void print(){
        if(head == NULL){
            std::cout<<"List is empty";
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            std::cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        std::cout<<temp->data<<" <-> "<<head->data;
    }
};

int main(){
    DoublyCLL dcll;
    dcll.insertatBeginning(12);
    dcll.insertatBeginning(11);
    dcll.insertatBeginning(10);
    dcll.insertatBeginning(9);
    dcll.print();
    std::cout<<std::endl;
    dcll.insertatEnd(3);
    dcll.print();
    std::cout<<std::endl;
    dcll.insertatEnd(45);
    dcll.print();
    std::cout<<std::endl;
    dcll.insertatK(90, 2);
    dcll.print();
}