#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

bool comp(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    return s1 < s2;
}

int main() 
{
    int n;
    std::cin >> n;
    std::set<std::string,comp> ar(1)
    
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }
    std::sort(ar.begin(), ar.end(), comp);
    for (int i = 0; i < n; i++) {
        std::cout << ar[i]<<std::endl;
    }
}