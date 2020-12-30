#include <iostream>
#include <cmath>
#include <string>

using namespace std;

uint64_t myR(double num, int p) {
    return num-floorl(num / p)*p;
}

uint64_t myP(int num, int e,int r) {
    uint64_t rslt = 1;
    for (int i = 0; i < e; i++) {
        rslt = ((rslt % r) * (num % r)) % r;
    }
    return rslt;
}

int main()
{
    int n;
    string s;
    uint64_t ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        
        ans = (ans % 1234567891 + ((s[i] - 'a'+1) * myP(31, i, 1234567891)) % 1234567891) % 1234567891;
    cout << ans;
}