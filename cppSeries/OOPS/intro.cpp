#include <iostream>

struct Date{
    int day{};
    int month{};
    int year{};
    void print(){
        std::cout<<year<<'/'<<month<<'/'<<day;
    }
    void print(std::string_view prefix){
        std::cout<<prefix<<year<<'/'<<month<<'/'<<day;
    }
};

class Dates{
public:
    int m_day{};
    int m_month{};
    int m_year{};
};

void printDates(const Dates& date){
    std::cout<<date.m_day<<'/'<<date.m_month<<'/'<<date.m_year;
}

void printDate(const Date& date){
    std::cout<<date.day<<'/'<<date.month<<'/'<<date.year<<"\n";
}

struct Person{
    std::string name{};
    int age{};
    void kisses(const Person& person){
        std::cout<<name<<" kisses "<< person.name;
    }
};


// classes with no data members
struct Foo{
    void printHi(){std::cout<<"Hello world\n";}
};
// consider using namespaces if you don't have any data members
namespace Foos{
    void printHii(){std::cout<<"Hello world\n";}
};
// if your class type has no data members, prefer using a namespace

struct IntPair{
    int first, second;
    void print(){
        std::cout<<"Pair("<<first<<", "<<second<<")\n";
    }
    bool isequal(IntPair a){
        return (first== a.first) && (second == a.second);
    }
};

int main(){
    Date date{4,10,21};
    date.print();
    std::cout<<"\n";
    Person joe{"Joe", 29};
    Person kate{"Kate", 27};
    joe.kisses(kate);
    std::cout<<'\n';
    date.print("The date is: ");
    std::cout<<"\n";
    Foo f;
    f.printHi();    // required object to call
    Foos::printHii();   // no object needed with namespace
    IntPair p1{1,2};
    std::cout<<"p1: ";
    p1.print();
    IntPair p2{3, 4};
    std::cout<<"p2: ";
    p2.print();
    
    return 0;
}