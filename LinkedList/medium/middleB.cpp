// find the middle node of the LL and return the Middle node
// Brute force approach
// TC: O(N/2) + O(N) => N being the size of LL
// SC: O(1)

#include <iostream>

class Node{
public:
    int data;
    Node* next;

    Node(int data)
    : data {data},
    next {nullptr}
    {}

    Node(int data, Node* next)
    : data {data},
    next {next}
    {}
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList()
    : head {nullptr}
    {}
};

Node* findMid(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    int midnode = (cnt/2 + 1);
    temp = head;
    while(temp != NULL){
        midnode--;
        if(midnode == 0) {break;}
        temp = temp->next;
    }
    return temp;
}