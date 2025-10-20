// Find the intersection of two linked lists
// solution : Difference in lengths of the LL

#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data)
    : data {data},
    next {nullptr}
    {}
};

// to insert node at the end of the LL
Node* insertNode(Node* head,int val) {
    Node* newNode = new Node(val);
    
    if(head == nullptr) {
        return newNode;
    }
    
    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    
    temp->next = newNode;
    return head;
}

Node* collisionNode(Node* temp1, Node* temp2, int diff){
    // since whichever list is shorter, (here temp1)
    // the temp2 will have to move steps forward to reach till the
    // same length starter point as temp1
    // that is why, i am moving temp2 ahead
    while(diff){
        diff--;
        temp2 = temp2->next;
    }
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;   // we can return temp2 here also, because they point to the same node anyways
}

Node *intersection(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    int len1 = 0, len2 = 0;
    // length of Fist LL
    while(t1 != NULL){
        len1++;
        t1 = t1->next;
    }
    // Length of second LL
    while(t2 != NULL){
        len2++;
        t2 = t2->next;
    }
    if(len1 < len2)
    {
        // fist LL is shorter than the second LL
        return collisionNode(head1, head2, len2-len1);
    }
    else{
        // second LL is shorter than the first LL
        return collisionNode(head2, head1, len1-len2);
    }
}

void printlist(Node* head){
    Node* temp = head;
    while(temp){
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }
    std::cout<<"NULL\n";
}

int main(){
    // creating two lists
    Node* head = NULL;
    head = insertNode(head, 3);
    head = insertNode(head, 1);
    head = insertNode(head, 4);
    head = insertNode(head, 2);
    head = insertNode(head, 6);

    Node* headsec = NULL;
    headsec = insertNode(headsec, 1);
    headsec = insertNode(headsec, 2);
    headsec = insertNode(headsec, 4);
    headsec = insertNode(headsec, 5);
    headsec = insertNode(headsec, 4);
    headsec = insertNode(headsec, 2);
    headsec = insertNode(headsec, 6);

    // create intersection manually
    // making node 5 in list2 point to the first node with value 4 in list 1
    Node* temp1 = head;
    while(temp1 && temp1->data != 4){
        temp1 = temp1->next;
    }

    Node* temp2 = headsec;
    while(temp2 && temp2->data != 5){
        temp2 = temp2->next;
    }
    if(temp1 && temp2){
        temp2->next = temp1;    // create intersection
    }

    std::cout<<"list1: ";
    printlist(head);
    std::cout<<"List2: ";
    printlist(headsec);
    Node* ans = intersection(head, headsec);
    if(ans == NULL){
        std::cout<<"No intersection found";
    }
    else{
        std::cout<<"The intersection point is: "<<ans->data<<std::endl;
    }
    return 0;
}