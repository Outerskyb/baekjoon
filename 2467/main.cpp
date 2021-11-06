#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = N - 1;

    int ans_left = vec[0];
    int ans_right = vec[N - 1];

    int sum = 2000000000;
    while (left != right) {
        if (abs(vec[left] + vec[right]) < sum) {
            ans_left = vec[left];
            ans_right = vec[right];
            sum = abs(vec[left] + vec[right]);
        }

        if (abs(vec[left + 1] + vec[right]) < abs(vec[left] + vec[right - 1])) {
            left += 1;
        }
        else {
            right -= 1;
        }
    }

    cout << ans_left << ' ' << ans_right;
}