#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sum=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }
    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << sum;
}