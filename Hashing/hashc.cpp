#include <iostream>
// C style implementation
#define SIZE 7

struct DataItem {
    int key;
    int data;
};

// array of pointers, each slot points to a DataItem
struct DataItem* hashArray[SIZE];
/*
a special marker pointer used during deletion in open addressing.

When you delete an element from a hash table that uses linear probing, you can’t simply set that cell to NULL.
Why? Because it would break the search chain.

So instead, we mark it with a dummy item (with a fake key like -1).
*/
struct DataItem* dummyItem;
// This is just a temporary pointer used inside the program (e.g. during insertion or search)
struct DataItem* item;

// hash function
int hashCode(int key){
    return key % SIZE;
}

struct DataItem *search(int key){
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == key){
            return hashArray[hashIndex];
        }
        // linear probing: move one step forward in the array.
        ++hashIndex;
        // wrap around the table when reaching end
        /*
        it ensures circular behavior.
        If hashIndex == SIZE (end of array),
        hashIndex % SIZE resets it to 0 (start of array).
        */
        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int key, int data){
    struct DataItem *item = new DataItem;
    // in c
    // struct DataIetem *newitem = (struct DataItem*)malloc(sizeof(struct Dataitem))
    item->data = data;
    item->key = key;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

struct DataItem* deletes(struct DataItem* item){
    int key = item->key;
    //get the hash
    int hashindex = hashCode(key);
    // move in array until an empty
    while(hashArray[hashindex] != NULL){
        if(hashArray[hashindex]->key == key){
            struct DataItem* temp = hashArray[hashindex];
            // assign a dummy value at deleted position
            hashArray[hashindex] = dummyItem;
            return temp;
        }
        ++hashindex;
        //wrap around the table
        hashindex %= SIZE;
    }
    return NULL;
}

void display(){
    for(int i=0; i<SIZE; i++){
        if(hashArray[i] != NULL){
            std::cout<<"("<<hashArray[i]->key<<","<<hashArray[i]->data<<") ";
        }
        else{
            std::cout<<"-- ";
        }
    }
    std::cout<<std::endl;
}

int main(){
    dummyItem = new DataItem;
    dummyItem->key = -1;
    dummyItem->data = -1;

    insert(50, 100);
    insert(700, 200);
    insert(76, 300);
    insert(85, 400);
    insert(92, 500);
    display();

    struct DataItem *item = search(92);
    if(item != NULL){
        std::cout<<"Found: "<<item->data<<std::endl;
    }
    else{
        std::cout<<"Not found\n";
    }
}
