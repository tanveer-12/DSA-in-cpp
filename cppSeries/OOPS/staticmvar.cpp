// intialization of static member variables inside the class definition

// - when the static member is a constant integral type
// which is(char or bool) or a const enum, the static member
// can be initialized inside the class definition

#include <iostream>

class Whatever{
    static const int s_value{4};
};

// an example of static member variables

class Something{
private:
    static inline int s_id{1};
    int m_id;
public:
    Something() // default constructor without any arguments
    : m_id {s_id++}
    {}
    int getID() const {return m_id;}
};

int main(){
    Something first{};
    Something second{};
    Something third{};

    std::cout<<first.getID()<<"\n";
    std::cout<<second.getID()<<"\n";
    std::cout<<third.getID()<<"\n";
    return 0;
}