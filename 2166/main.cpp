#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

double getArea(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
    return ((p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
        - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first))*0.5;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<double, double>> vec;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({ b,a });
    }
    /*
    sort(vec.begin(), vec.end(), [](pair<double, double>p1, pair<double, double>p2) {
            return atan2(p1.first, p1.second) < atan2(p2.first, p2.second);
        }
    );
    */

    double ans = 0;
    for (int i = 1; i < N-1; i++) {
        ans += getArea(vec[0], vec[i], vec[i + 1]);
    }

    printf("%.1lf", abs(ans));
}