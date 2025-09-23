// setting access levels via access specifiers
#include <iostream>

class Date{
    // any members defined here would default to private
public:
    void print() const{
        // members can access other private members
        std::cout<<m_year<<'/'<<m_month<<'/'<<m_day;
    }

    int m_year{2024};
    int m_month{14};
    int m_day{10};
};

class Person{
private: 
    std::string m_name{};
public:
    void kisses(const Person & p) const{
        std::cout<<m_name<<" kisses "<<p.m_name;
    }
    void setName(std::string_view name){
        m_name = name;
    }
};

int main(){
    Date d; //members are private therefore cannot aggregate initialize d
    d.print(); // for this eg, we're using default member initialization
    Person joe;
    std::cout<<"\n";
    joe.setName("Joe");
    Person kate;
    kate.setName("Kate");
    kate.kisses(joe);
    return 0;
}