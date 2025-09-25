// constructors are allowed to call other functions,
// including other member functions of the class

#include <iostream>
#include <string>
#include <string_view>

class Employee{
private:
    std::string m_name {"???"};
    int m_id{0};
    bool m_is_Manager{false};
    void printCreate() const{   // our new helper function
        std::cout<<"Employee "<<m_name<<" created\n";
    }
public:
    Employee(std::string_view name, int id)
    : m_name {name}, m_id {id}
    {
        printCreate();  // we call it here
    }
    Employee(std::string_view name, int id, bool isManager)
    :m_name{name}, m_id{id}, m_is_Manager{isManager}
    {
        printCreate();  // and here
    }
};

int main(){
    Employee e1{"James", 7};
    Employee e2{"Dave", 42, true};
    return 0;
}