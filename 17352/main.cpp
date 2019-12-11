#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> vec;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N - 2; i++) {
        int a, b;
        cin >> a >> b;
        vec[a] = b;
    }
}