// downcasting: converting base pointer/ref to a derived class pointer/ref
// you must ensure that the obj is actually of that derived type

// safe downcasting with dynamic_cast
// perform derived-specific operations when all you have is a base pointer

#include <iostream>
#include <vector>

class Entity{
public:
    virtual void update() const = 0; 
    virtual ~Entity(){}
};

class Player: public Entity{
public: 
    void update() const override{
        std::cout<< "Player moves\n";
    }
    void attack(){
        std::cout<<"Player attacks\n";
    }
};

class Enemy : public Entity{
public:
    void update() const override{
        std::cout<<"Enemy moves\n";
    }
    void attack() {
        std::cout<<"Enemy attacks\n";
    }
};


int main(){
    std::vector<Entity*> gameobjects;
    gameobjects.push_back(new Player());
    gameobjects.push_back(new Enemy());
    gameobjects.push_back(new Player());
    for(auto obj: gameobjects){
        // try to downcast to player
        Player* player = dynamic_cast<Player*>(obj);
        if(player){
            player->attack();   // only called for player
        }
        Enemy* enemy = dynamic_cast<Enemy*>(obj);
        if(enemy){
            enemy->attack();    // only called for enemy
        }
    }
    for(Entity* obj: gameobjects){
        delete obj;
    }
    return 0;
}