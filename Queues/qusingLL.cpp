/*  IMPLEMENTING QUEUE USING LINKED LISTS

TC - O(1) for push, pop, peek operations
SC - O(1)
*/

#include <bits/stdc++.h>

class listQueue{
    class Node{
    public:
        int data;
        Node *next;

        Node(int x)
        : data{x},
        next{nullptr}
        {}
    };
    Node *head;
    Node *tail;
    int size;
public:
    listQueue()
    : head{nullptr},
    tail{nullptr},
    size{0}
    {}

    ~listQueue(){
        while(head != nullptr){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // enqueue operation
    void enqueue(int x){
        Node *node = new Node(x);
        if(head == nullptr){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        size++;
    }

    // Dequeue operation
    // here we are returning the removed element
    int dequeue(){
        if(head == nullptr){
            std::cout<<"Queue is empty";
            return -1;
        }
        Node *temp = head;
        int removedVal = temp->data;
        head = head->next;

        // if head reaches to null, make the tail point to null too 
        // since it mean the queue is empty now
        if(head == nullptr){
            tail = nullptr;
        }

        delete temp;
        size --;
        return removedVal;
    }

    // get front element
    int getfront(){
        if(head == nullptr){
            std::cout<<"Queue is empty";
            return -1;
        }
        return head->data;
    }
};

int main(){
    listQueue qq;
    qq.enqueue(1);
    qq.enqueue(2);
    qq.enqueue(3);
    std::cout<<"Front element is: "<<qq.getfront() <<std::endl;
    qq.dequeue();
    qq.dequeue();
    std::cout<<"Front element after dequeue is: "<<qq.getfront()<<std::endl;
    qq.enqueue(4);
    qq.enqueue(5);
    qq.enqueue(6);
    qq.enqueue(7);
    std::cout<<"Front element is: "<<qq.getfront()<<std::endl;
    return 0;
}