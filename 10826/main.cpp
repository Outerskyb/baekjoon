#include <iostream>

using namespace std;

int main()
{
    int n;
    long long now = 1;
    long long prev = 1;
    long long pprev = 0;

    cin >> n;
    for (int i = 2; i <= n; i++) {
        now = pprev + prev;
        pprev = prev;
        prev = now;
    }
    cout << (n?now:0);
}