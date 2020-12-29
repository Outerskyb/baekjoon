#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    vector<int> LIS;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++) {
        if (LIS.empty() || LIS.back() < input[i])LIS.push_back(input[i]);
        else *lower_bound(LIS.begin(), LIS.end(), input[i])=input[i];
    }
    cout << n - LIS.size();
}