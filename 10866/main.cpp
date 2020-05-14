#include <iostream>
#include <vector>
#include <algorithm>
#include <cinttypes>

using namespace std;

vector<int64_t> vec;

void func(int64_t curr) {
    if (vec.size() >= 1000000) return;
    vec.push_back(curr);
    for (int i = curr % 10-1; i >= 0; i--) {
        func(curr * 10 + i);
    }
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++) func(i);
    sort(vec.begin(), vec.end());
    cout << ((n > vec.size()) ? -1 : vec[n-1]);
    

}