#include <iostream>
#include <string>
#include <string_view>

class Employee{
    std::string m_name{"John"};     // defaults to John
public:
    void setName(std::string_view name){
        m_name = name;
    }
    char firstInitial() const {return m_name.front();}
    void print() const{
        std::cout<<"Employee "<<m_name<<" has first initial "<<firstInitial()<<"\n";
    }
};

int main(){
    Employee e{};
    e.setName("Mark");
    e.print();
    return 0;
}