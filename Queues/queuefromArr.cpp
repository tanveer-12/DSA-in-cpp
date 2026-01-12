/*      QUEUE IMPLEMENTATION USING ARRAYS
    FIFO - FIRST IN FIRST OUT
*/

// USING FIXED-SIZED ARRAYS AND SIMPLE IMPLEMENTATION
// Enqueue (insertion) 	                O(1)
// Deque (deletion)   	                O(n)
// Front (Get front)   	                O(1)
// Rear (Get Rear)	                    O(1)
// IsFull (Check queue is full or not)	O(1)
// IsEmpty(Check queue is empty or not)	O(1)

#include <bits/stdc++.h>

class myBasicQueue{
    int *queue; // queue array to store elements
    int capacity;   // maximum number of elements the queue can hold
    int size;   // current number of elements in the queue
    int front, rear;
public:
    // constructor
    myBasicQueue(int cap)
    : capacity{cap}, 
    size{0},
    front{0},
    rear{-1}
    {
        queue = new int[capacity];
    }

    ~myBasicQueue(){
        delete[] queue;
    }

    // function to add an element to the queue (since the elements are added to the rear)
    void enqueue(int x){
        if(size == capacity){
            std::cout<<"Queue is full. Cannot insert the element "<<x<<std::endl;
            return;
        }
        // when the queue not full, move the rear end ahead
        rear++;
        // place the element at this rear end
        queue[rear] = x;
        // increment the size by 1
        size++;
    }

    // function to remove an element from the queue (element is added from the front since FIFO)
    void dequeue(){
        if(size == 0){
            std::cout<<"Queue underflow. no element is to be deleted";
            return;
        }
        // shift all remaining elements forward one position
        for(int i=front; i< rear; i++){
            queue[i] = queue[i+1];
        }
        // decrement the rear
        rear--;
        // decrement the size by 1
        size--;
    }

    // function to get the front element
    int peek(){
        if(size == 0){
            std::cout<<"Queue is empty. No front element";
            return -1;
        }
        // otherwise return the front element
        return queue[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }
};

// queue implementation implementing circular queue method or modular arithmetic method
// Enqueue (insertion) 	                O(1)
// Deque (deletion)   	                O(1)
// Front (Get front)                	O(1)
// Rear (Get Rear)                  	O(1)
// IsFull (Check queue is full or not)	O(1)
// IsEmpty(Check queue is empty or not)	O(1)

class myQueue{
    // Fixed-size array to store queue elements
    int* queue;
    // Index of the front element
    int front;
    // Current number of elements in the queue
    int size;
    // Maximum capacity of the queue
    int capacity;
public:
    // Constructor to initialize the queue with given capacity
    myQueue(int cap)
    : capacity{cap},
    size{0},
    front{0}
    {
        queue = new int[capacity];
    }

    // Insert an element at the rear/back
    // Check for full queue: If size == capacity, the queue is full print message or return.
    // Compute rear index: rear = (front + size) % capacity ensures circular behavior.
    // Insert element: arr[rear] = x.
    // Update size: Increment size by 1.
    // Time Complexity: O(1) Space Complexity: O(1) for the array
    void enqueue(int x){
        if(size == capacity){
            std::cout<<"Queue is full. Cannot insert the element "<<x;
            return;
        }
        int rear = (front + size) % capacity;
        queue[rear] = x;
        size++;
    }

    // remove and return the front element from the circular queue
    // Check for empty queue: If size == 0, the queue is empty print message or return -1.
    // Retrieve front element: res = arr[front].
    // Move front forward: front = (front + 1) % capacity circular movement.
    // Update size: Decrement size by 1.
    // Return element: Return res.
    // Time Complexity: O(1) Space Complexity: O(1)
    int dequeue(){
        if(size == 0){
            std::cout<<"Queue is empty.";
            return -1;
        }
        int result = queue[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }

    // but if we don't want to return the result
    void dequeuer(){
        if(size == 0){
            std::cout<<"Queue is empty";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    // return the element at the rear of the circular queue
    int getrear(){
        if(size == 0){
            std::cout<<"Queue is empty";
            return -1;
        }
        // compute rear index: rear = (front + size - 1) % capacity
        int rear = (front + size - 1) % capacity;
        return queue[rear];
    }

    // return the element at the front of the circular queue
    int getfront(){
        if(size == 0){
            std::cout<<"Queue is empty";
            return -1;
        }
        // otherwise just return
        return queue[front];
    }
};

int main(){
    myBasicQueue q(5);  // simple queue obj
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front element is: " << q.peek() << std::endl;
    q.dequeue();
    q.dequeue();
    std::cout << "Front element after dequeues is: " << q.peek() << std::endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.enqueue(70); 
    std::cout << "Front element is: " << q.peek() << std::endl;
    q.enqueue(80); // This will show a "Queue is full" message

    myQueue qq(5);  //circular queue obj of capacity = 5
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
    qq.enqueue(8);  // this will show error
    return 0;
}