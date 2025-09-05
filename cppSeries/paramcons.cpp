/*
Just like normal functions, we can also define default 
values for the arguments of parameterized constructors. 
All the rules of the default arguments will be applied 
to these parameters.
*/

#include <iostream>
#include <string.h>

class Student{
    int rno;
    std::string name;
    double fee;

public:
    //declaration of parameterized constructors
    Student(int, std::string, double);
    void display();
};

// parameterized constructor outside class
Student::Student(int no, std::string n, double f){
    rno =no;
    name = n;
    fee = f;
}

void Student::display(){
    std::cout<<rno<<"\t"<<name<<"\t"<<fee<<std::endl;
}

class A{
public:
    int data;
    //parameterized constructor with default values
    A(int x =5) {data=x;}
};

int main(){
    A a1;
    A a2(25);
    std::cout<<a1.data<<std::endl;
    std::cout<<a2.data<<"\n";
    Student s(1000, "Tanveer", 10000);
    s.display();
    return 0;
}