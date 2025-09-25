/*
 The member function implementations clutter up the public 
 interface with details that aren’t relevant to actually 
 using the class.

To help address this, C++ allows us to separate the 
“declaration” portion of the class from the “implementation” 
portion by defining member functions outside of the class 
definition.
*/

#include <iostream>

class Date{
private: 
    int m_year{};
    int m_month{};
    int m_day{};
public:
    Date(int year, int month, int day);     // const declaration
    void print() const;     // print func declaration
    int getYear() const {return m_year;}
    int getMonth() const {return m_month;}
    int getDay() const {return m_day;}
};

Date::Date(int year, int month, int day)
: m_year{year}, m_month{month}, m_day{day}
{

}

void Date::print() const{
    std::cout<<m_year<<"/"<<m_month<<"/"<<m_day<<"\n";
}

int main(){
    const Date dt{2025, 9, 24};
    dt.print();
    return 0;
}