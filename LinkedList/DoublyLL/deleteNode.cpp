// delete nodes in doubly linked lists

#include <iostream>
#include <vector>

class Node{
public: 
    int data;
    Node* next;
    Node* back;
    Node(int data)
    : data{data},
    next{nullptr},
    back{nullptr}
    {}
    Node(int data, Node* next, Node* back)
    : data{data},
    next{next},
    back{back}
    {}
};

Node* arrtoDLL(std::vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

// Deleting the Node at the beginning
Node* deleteBegin(Node* head){
    // if the list is empty or there is only one node in the LL
    if(head==NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr; 
    delete prev;
    return head;
}

// Deleting the Tail Node
Node* deleteTail(Node* head){
    if(head==NULL || head->next == NULL){
        return NULL;
    }
    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

// Deleting the Kth node
Node* deletekthnode(Node* head, int k){
    // if the DLL is empty
    if(head==NULL){
        return NULL;
    }
    int cnt = 0;
    Node* knode = head;
    while(knode != NULL){
        cnt++;
        if(cnt == k) {break;}
        knode = knode->next;
    }
    Node* prev = knode->back;
    Node* front = knode->next;
    // edge case1: when there is only one node in the DLL
    if(prev==NULL && front==NULL){
        return NULL;
    }
    // edge case2: when the kth node is the head node
    else if(prev == NULL){
        return deleteBegin(head);
    }
    // case3: when the kth node is the tail node
    else if(front==NULL){
        return deleteTail(head);
    }
    // case4: when it is an intermediate node
    prev->next = front;     // prev->next = knode->next;
    front->back = prev;     // front->back = knode->back;
    knode->next = nullptr;  // unlinking the knode
    knode->back = nullptr;  // unlinking the knode
    delete knode;           // deallocatiing the knode from the memory
    return head;
}

void display(Node* head){
    while(head){
        std::cout<<head->data<<" -> ";
        head = head->next;
    }
    std::cout<<"NULL";
}

int main(){
    std::vector<int> arr = {2,3,1,4,7,6,8,9};
    Node* head = arrtoDLL(arr);
    std::cout<<"Initial list: ";
    display(head);
    std::cout<<std::endl;
    head = deleteBegin(head);
    display(head);
    std::cout<<std::endl;
    head = deleteTail(head);
    display(head);
    std::cout<<std::endl;
    head = deletekthnode(head,4);
    display(head);
    return 0;
}