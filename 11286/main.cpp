#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (temp == 0) {
            if (s.size() == 0) cout << "0\n";
            else {
                cout << s.top().second << '\n';
                s.pop();
            }
        }
        else
            s.push({ abs(temp),temp });
    }
}