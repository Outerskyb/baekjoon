#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> LIS;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
        if (LIS.empty() || LIS.back() < vec[i]) LIS.push_back(vec[i]);
        else *lower_bound(LIS.begin(), LIS.end(), vec[i]) = vec[i];
    }
    cout << n - LIS.size();
}