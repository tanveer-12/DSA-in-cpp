// casting: how you convert a pointer or reference from one type to another. when
// inheritance comes into play, this is usually upcasting and downcasting

// UPCASTING: converting a pointer/ref from a derived class to a base class
// done implicitly (no cast needed) in C++
// enables polymorphism - treats multiple dervied types in a uniform way

#include <iostream>
#include <vector>

class Entity{
public:
    virtual void update() = 0; 
    virtual ~Entity(){}
};

class Player: public Entity{
public: 
    void update() override{
        std::cout<< "Player moves\n";
    }
    void attack(){
        std::cout<<"Player attacks\n";
    }
};

class Enemy : public Entity{
public:
    void update() override{
        std::cout<<"Enemy moves\n";
    }
    void attack() {
        std::cout<<"Enemy attacks\n";
    }
};

int main(){
    Player* p = new Player();
    Enemy* e = new Enemy();

    //upcasting: derived to base (automatic)
    Entity* entity1 = p;
    Entity* entity2 = e;

    entity1->update(); // player moves
    entity2->update(); // enemy moves

    // store multiple derived objects in a single container
    std::vector<Entity*> gameObjects;
    gameObjects.push_back(p);
    gameObjects.push_back(e);

    for(const auto obj: gameObjects){
        obj->update();
    }

    // destructor 
    for(size_t i=0;i<gameObjects.size(); i++){
        delete gameObjects[i];
    }
    return 0;
}

