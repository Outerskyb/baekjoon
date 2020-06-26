#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
    int n;
    cin >> n;
    uint64_t pprev = 0;
    uint64_t prev = 1;
    uint64_t now = 1;
    for (int i = 2; i <= n; i++)
        now = (pprev % 1000000007 + prev % 1000000007) % 1000000007, pprev = prev, prev = now;
    cout << (n ? now : 0);
}