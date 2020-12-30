#include <iostream>
#include <cmath>
#include <string>

using namespace std;

uint64_t myR(double num, int p) {
    return num-floorl(num / p)*p;
}

int main()
{
    int n;
    string s;
    uint64_t ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        ans = (ans % 1234567891 + myR((((double)s[i] - 'a'+1) * pow(31, i)) , 1234567891)) % 1234567891;
    cout << ans;
}