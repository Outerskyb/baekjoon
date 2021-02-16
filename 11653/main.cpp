#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool pri[10000001] = { 0,0,1,1 };
vector<int> prime;
void get_pri() {
    memset(pri, 1, sizeof pri);
    for (int i = 2; i <= 10000000; i++) {
        if (pri[i]) prime.push_back(i);
        else continue;
        for (int j = i*2; j <= 10000000; j += i) {
            pri[j] = 0;
        }
    }
}



int main()
{
    get_pri();
    int n;
    cin >> n;
    vector<int> divs;
    while (n > 1) {
        for (int i = 0; i <= 10000000; i++) {
            if (n % prime[i]==0) {
                divs.push_back(prime[i]);
                n /= prime[i];
                break;
            }
        }
    }
    sort(divs.begin(), divs.end());
    for (const auto& el : divs) {
        cout << el << '\n';
    }
}