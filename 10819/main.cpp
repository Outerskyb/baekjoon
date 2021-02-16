#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int get_val(vector<int> vec) {
    int ret = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        ret += abs(vec[i] - vec[i + 1]);
    }
    return ret;
}

int main()
{
    int n;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int ans = get_val(vec);
    while (next_permutation(vec.begin(), vec.end())) {
        ans = max(ans, get_val(vec));
    }
    ans = max(ans, get_val(vec));
    cout << ans;
}