#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> p, m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp > 0)
            p.push_back(temp);
        else
            m.push_back(temp);
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    int sum = 0;
    if (p.size() > 1)
        for (int i = p.size() - 1; i >= 0; i--) {
            if (i > 1 && p[i - 1] > 1)
                sum += p[i] * p[i - 1], i--;
            else
                sum += p[i];
        }
    if (p.size() > 0)
        sum += (p.size() % 2) * p.front();
    if (m.size() > 1)
        for (int i = 0; i < m.size() / 2 * 2; i += 2) {
            sum += m[i] * m[i + 1];
        }
    if (m.size() > 0)
        sum += (m.size() % 2) * m.back();

    cout << sum;
}