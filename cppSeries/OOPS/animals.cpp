#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

enum class AnimalType{
    dogs,
    cats,
    deers,
    horses,
    cows
};
std::string to_string(AnimalType t) {
    switch (t) {
        case AnimalType::dogs: return "dogs";
        case AnimalType::cats: return "cats";
        case AnimalType::cows: return "cows";
        case AnimalType::horses: return "horses";
        case AnimalType::deers: return "deers";
        default: break;
    }
    return "unknown";
}
class Animal {
public:
    Animal(const std::string& name) : m_Name(name) {}
    virtual ~Animal() {} // very important if ...
    std::string name() const {
        return m_Name;
    }
    virtual std::string sound() const = 0;
    virtual AnimalType type() const = 0;
    //virtual std::string type() const = 0;
private:
    std::string m_Name;
};

class Dog: public Animal{
public:
    Dog(const std::string& name)
    : Animal(name) {
        a = new int();
    }
    ~Dog() {
        std::cout << "\nDog Destructor..";
        delete a;
    }
    std::string sound() const override {
        return "Woof";
    }
    AnimalType type() const override{
        return AnimalType::dogs;
    }
    // std::string type() const override{
    //     return "dogs";
    // }
    std::string name() const {
         return "dog";
    }
private:
    int *a ;
};
class Cat: public Animal{
public:
    Cat(const std::string& name, const std::string& sound)
    : Animal(name), sound_(sound){}

    std::string sound() const override {
        return sound_;
    }
    // std::string type() const override{
    //     return "cats";
    // }
    AnimalType type() const override{
        return AnimalType::cats;
    }
private:
    std::string sound_;
};
class Deer: public Animal{
public:
    Deer(const std::string& name, const std::string& sound)
    : Animal(name), sound_(sound){}

    std::string sound() const override {
        return sound_;
    }
    // std::string type() const override{
    //     return "deers";
    // }
    AnimalType type() const override{
        return AnimalType::deers;
    }
private:
    std::string sound_;
};
class Horse: public Animal{
public:
    Horse(const std::string& name, const std::string& sound)
    : Animal(name), sound_(sound){}

    std::string sound() const override {
        return sound_;
    }
    // std::string type() const override{
    //     return "horses";
    // }
    AnimalType type() const override{
        return AnimalType::horses;
    }
private:
    std::string sound_;
};
class Cow : public Animal {
public:
    Cow(const std::string& name, const std::string& sound)
    : Animal(name), sound_(sound){}
    std::string sound() const override {
        return sound_;
    }
    // std::string type() const override{
    //     return "cows";
    // }
    AnimalType type() const override{
        return AnimalType::cows;
    }
private:
    std::string sound_;
};

// TODO: in ANimal , add method type which should be pure virtual
// derive class tells their type
// then tell how many types of animals are there in the animal vector based on their type


int main(){
    std::vector<Animal*> animal;
    Animal *d = new Dog("Caesar");
 //   Dog *d1 = new Dog("x", "y");
   // std::cout << d1->name() << "\n";
    animal.push_back(d);
    animal.push_back(new Cat("Katy", "Meow"));
    animal.push_back(new Deer("Doo", "whatever"));
    animal.push_back(new Dog("Mufy"));
    animal.push_back(new Dog("Sheru"));
    animal.push_back(new Cat("Karen", "Meow"));
    animal.push_back(new Horse("Black Beauty", "Neigh"));
    animal.push_back(new Cow("Pepper", "Moo"));
    animal.push_back(new Cow("Nika", "Moo"));
    animal.push_back(new Cat("Bob", "Meow"));

    for(const auto a: animal){
        std::cout<< a->name() << " says " << a->sound() << "\n";
    }
    
    //std::unordered_map<std::string, int> typeCount;
    std::unordered_map<AnimalType, int> typeCount;
    for(const auto m: animal){
        typeCount[m->type()]++;
    }
    std::cout<< "\n==== Printing count of Type of Animals ====\n";
    for(const auto& [type, count]:typeCount){
        std::cout<< to_string(type) << " : " << count << "\n";
    }
   // delete d1;
    // No need to do this with smart pointers: TODO
    for(size_t i = 0; i < animal.size(); ++i) {
        delete animal[i];
    }
    return 0;
}

// Open-Close Principle