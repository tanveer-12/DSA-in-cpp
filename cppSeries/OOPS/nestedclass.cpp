/*
a nested class does not have access to the this pointer of the outer 
(containing) class, so nested classes can not directly access the members of the 
outer class. This is because a nested class can be instantiated independently of 
the outer class (and in such a case, there would be no outer class members to 
access!)

However, because nested classes are members of the outer class, they can access 
any private members of the outer class that are in scope.
*/

#include <iostream>

class Employee{
public:
    using IDtype = int; 
    class Printer{
        public:
            void print(const Employee &e) const{
                std::cout<<e.m_name<<" has id: "<<e.m_id<<"\n";
            }
    };
private:
    std::string m_name{};
    IDtype m_id{};
    double m_wage{};

public:
    Employee(std::string_view name, IDtype id, double wage)
    :m_name{name},
    m_id{id},
    m_wage{wage}
    {}

    //removed the access functions in this example since they are not used
};

int main(){
    const Employee john{"John", 1, 45000};
    const Employee::Printer p{};    // instantiate an obj of inner class
    p.print(john);
    return 0;
}