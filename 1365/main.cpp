#include <iostream>
#include <algorithm>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vector<int> L;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        if (L.empty() || L.back() < vec[i])
            L.push_back(vec[i]);
        else {
            auto it = lower_bound(L.begin(), L.end(), vec[i]);
            *it = vec[i];
        }
    }
    

    cout << n-L.size();
}