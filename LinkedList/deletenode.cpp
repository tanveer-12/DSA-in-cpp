// Deleting node in Singly LL

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

class LinkedList{
private:
    Node* head;
public:
    LinkedList()
    : head{nullptr}
    {}
    // destructor: Free all nodes
    ~LinkedList()
    {
        Node* curr = head;
        while(curr){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // deleting the Node at the begining
    void deleteBegin(){
        if(!head){  // if head is null
            std::cout<<"List is empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;    // delete in LL: unlink + delete the allocated memory for that node
    }

    // Deleting the node at the end
    void deleteEnd(){
        if(!head){
            std::cout<<"List is empty";
            return;
        }
        // if there is only one node
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        // Deleting from end
        Node* prev = nullptr;
        Node* curr = head;

        // traverse till the end
        while(curr->next){
            prev = curr;    // becomes previous node to the tail node
            curr = curr->next;      // becomes the tail node
        }
        prev->next = nullptr;   //unlink the last node
        delete curr;    // free last node
    }

    // Deleting an intermediate node in the singly LL
    // 1 indexed position i.e. position 1 = head
    void deletePosition(int pos){
        // case 1: empty list
        if(!head){  // or if(head==nullptr)
            std::cout<<"List is empty";
            return;
        } 

        // case2: if the position is head
        if(pos == 1){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // case3: deleting the intermediate or last node
        Node* prev = nullptr;
        Node* curr = head;

        // traverse till (pos - 1)th node
        for(int i=0; i<pos && curr!=nullptr; i++){
            prev = curr;
            curr = curr->next;
        }

        // if position is out of range
        if(curr == nullptr){    //i.e. at the end
            std::cout<<"Position is out of range";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }
    // -----------------------
    // to test the delete func, need to insert some nodes
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
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
    LinkedList ll;

    // building initial list: 10-> 20-> 30-> 40-> NULL
    ll.insertEnd(10);
    ll.insertEnd(20);
    ll.insertEnd(30);
    ll.insertEnd(40);

    std::cout<<"Initial list: ";
    ll.display();

    // testing deleteBegion
    std::cout<<"\nDeleting first node: ";
    ll.deleteBegin();
    ll.display();

    //testing deleteEnd()
    std::cout<<"\nDeleting last node: ";
    ll.deleteEnd();
    ll.display();

    // testing deletePosition
    std::cout<<"\nDeleting node at position 2 (0-indexed): ";
    ll.deletePosition(1);
    ll.display();

    // Try deleting from empty list
    std::cout << "\nDeleting from empty list (after all deletions): ";
    ll.deleteBegin();  // Should print "List is empty"
    std::cout << "\n";
    ll.display();
    ll.deleteBegin();

    // Rebuild list for out-of-range test
    ll.insertEnd(100);
    ll.insertEnd(200);
    std::cout << "\nRebuilt list: ";
    ll.display();  // 100 -> 200 -> NULL

    std::cout << "Trying to delete position 5 (out of range): ";
    ll.deletePosition(5);  // Should print "Position is out of range"
    std::cout << "\nFinal list: ";
    ll.display();

    return 0;
}