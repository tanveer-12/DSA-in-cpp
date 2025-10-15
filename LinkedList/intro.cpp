#include <iostream>
#include <vector>

// --- testing github desktop----
class Node{
public:
    int data;
    Node* next;

    Node(int data)
    : data{data},
    next{nullptr}
    {}

    Node(int data, Node* next)
    : data{data},
    next{next}
    {}
};

int main(){
    std::vector<int> arr = {2,4,5,6};
    Node x = Node(arr[1],nullptr);
    Node *y = &x;

    // or 
    Node* z = new Node(arr[1], nullptr);
    std::cout<<y->data<<std::endl;
    std::cout<<y->next;
    std::cout<<z->data<<std::endl;
    std::cout<<z->next;
}