#include <iostream>
#include <algorithm>
#include <string>

int main() 
{
    std::string str;
    std::cin >> str;
    std::sort(str.begin(), str.end());
    std::reverse(str.begin(), str.end());
    std::cout << str;
}