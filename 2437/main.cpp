#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> weights;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());
    if (weights[0] != 1) {
        cout << 1;
        return 0;
    }
    int sum = weights[0];
    for (int i = 1; i < n; i++) {
        if (weights[i] > sum+1) {
            break;
        }
        sum += weights[i];
    }
    cout << sum + 1;
    return 0;
}