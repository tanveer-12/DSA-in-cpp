// class template exercise question #1 for 15.5
/*
Write a class template named Triad that has 3 private data members 
with independent type template parameters. The class should have a 
constructor, access functions, and a print() member function that is 
defined outside the class.
*/

#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad{
private: 
    T m_first {};
    U m_second {};
    V m_third {};
public:
    Triad(const T& first, const U& second, const V& third)
    :m_first{first},
    m_second {second},
    m_third {third}
    {}
    const T& first() const {return m_first;}
    const U& second() const {return m_second;}
    const V& third() const {return m_third;}
    void print() const;
};


template <typename T, typename U, typename V>
void Triad<T,U, V>::print() const{
    std::cout<<"{"<<m_first<<", "<<m_second<<", "<<m_third<<"\n";
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
    // could have been written as
    // Triad t1 {1,2,3}
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
    // this is equal to
    // const Triad<int, double, std::string> t2{1, 2.3, "hello"s}
	t2.print();
	std::cout << '\n';

	return 0;
}