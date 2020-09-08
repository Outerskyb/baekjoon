#include <iostream>
#include <vector>
#include <algorithm>
#include <cinttypes>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    vector<uint64_t> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    uint64_t l = 0;
    uint64_t h = 1000000001;
    sort(vec.begin(), vec.end());
    while (l + 1 < h) {
        uint64_t mid = (l + h) / 2;
        int cnt = 0;
        uint64_t len = 0;
        for (int i = 1; i < n; i++) {
            if (len + vec[i] - vec[i - 1] > mid) {
                len = 0;
                cnt++;
            }
            else {
                len += vec[i] - vec[i - 1];
            }
        }

        if (cnt < c) {
            h = mid;
        }
        else {
            l = mid;
        }
    }

    cout << h;
}