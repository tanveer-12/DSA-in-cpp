// Return true or false if the given number is armstrong num
// num = 153
// 153 = 1^3 + 5^3 + 3^3 => 153
// num == 153 so it is a armstrong number

#include <iostream>
#include <cmath>

int CountDigits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

void ArmstrongNum(int num, int digits)
{
    int n = num, ans = 0, remainder;
    while (n)
    {
        remainder = n % 10;
        n /= 10; // n = n/10
        ans = ans + pow(remainder, digits);
    }
    if (ans == num)
        std::cout<<"True"<<std::endl;
    else
        std::cout<<"False"<<std::endl;
}

int main()
{
    std::cout << "num: " << std::endl;
    int num;
    std::cin >> num;
    int digit = CountDigits(num);
    ArmstrongNum(num, digit);
    return 0;
}