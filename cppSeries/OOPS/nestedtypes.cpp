// 15.3 -> nested types

#include <iostream>

enum class FruitType{
    apple,
    banana,
    cherry
};

class Fruit{
private:
    FruitType m_type{};
    int m_percentageEaten{0};

public:
    Fruit(FruitType type)
    : m_type { type }
    {}

    FruitType getType() {return m_type;}

    int getPercentageEaten() {return m_percentageEaten;}

    bool isCherry() {return m_type==FruitType::cherry;}
};

// or it can be nested inside the fruit class under appropriate access specifier
class Fruits{
public: 
// FruitType has been moved inside the class, under the piblic access
// specifier. We've also renamed it Type and made it an enum rather than 
// an enum class
    enum Type{
        apple,
        banana,
        cherry
    };
private: 
    Type m_type{};
    int m_percentageEaten{0};
public: 
    Fruits(Type type)
    :m_type{type}{
    }
    Type getType() {return m_type;}
    int getpercentageEaten() {return m_percentageEaten;}

    bool isCherry() {return m_type==cherry;} //inside members of Fruits, we no
    // longer need to prefix enumerators with FruitType:
};

int main(){
    Fruit apple {FruitType::apple};
    if(apple.getType() == FruitType::apple){
        std::cout<<"I am an apple";
    }
    else{
        std::cout<<"I am not an apple";
    }

    // outside the class, we access the enumerators via the
    // Fruist:: prefix
    Fruits apples {Fruits::apple};
    if(apples.getType() == Fruits::apple){
        std::cout<<"I am an apple";
    }
    else{
        std::cout<<"I am not an apple";
    }
    return 0;
}