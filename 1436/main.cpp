#include <iostream>

using namespace std;

bool isShom(int num) {
    if (num < 666) return 0;
    int prev = 0,pprev = 0,now = 0;
    while (num > 0) {
        now = num % 10;
        num /= 10;
        if (now == pprev && pprev == prev && prev == 6) return 1;
        pprev = prev, prev = now;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 666; i < 10000667; i++) {
        if (isShom(i)) {
            --n;
            if (n == 0) {
                cout << i;
                return 0;
            }
        }
    }
}