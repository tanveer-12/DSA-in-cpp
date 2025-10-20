/*
Given the heads of two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.
*/

// TC - O(max(N1, N2)) => N being the size of the LL
// SC - O(max(n1, N2))

#include <iostream>
#include <vector>

class Node{
public:
    int data;
    Node* next;

    Node()
    : data {0},
    next {nullptr}
    {}

    Node(int data)
    : data{data},
    next{nullptr}
    {}

    Node(int data, Node* next)
    : data {data},
    next {nullptr}
    {}

    Node* arrtoLL(std::vector<int> & arr){
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1; i<arr.size(); i++){
            Node* newnode = new Node(arr[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return head;
    }
};

class Solution{
public: 
    Node* addTwoLL(Node* l1, Node* l2){
        // create a dummy node
        Node* dummy = new Node();
        Node* curr = dummy;     // curr is for the traversal of the resulting LL
        int carry = 0;
        while(l1 != NULL|| l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            Node* newnode = new Node(sum % 10);
            curr->next = newnode;
            curr = curr->next;
        }
        return dummy->next;
    }   
    void display(Node* head){
        Node* temp = head;
        while(temp!= NULL){
            std::cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        std::cout<<"NULL";
    }
};

int main(){
    std::vector<int> array1 = {2,4,6};
    std::vector<int> array2 = {3,8,7};
    Node n1;
    Node* head1 = n1.arrtoLL(array1);
    Node* head2 = n1.arrtoLL(array2);
    Solution sl;
    std::cout<<"List1: ";
    sl.display(head1);
    std::cout<<"\nList2: ";
    sl.display(head2);
    Node* head = sl.addTwoLL(head1, head2);
    std::cout<<"\nResult: ";
    sl.display(head);
    return 0;
}