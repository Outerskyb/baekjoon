#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input;
    pair<int, int> cnt[8001] = { {0,0} };
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
        sum += temp;
        cnt[temp + 4000] = { cnt[temp + 4000].first + 1,temp };
    }

    sort(input.begin(), input.end());
    sort(cnt, cnt + 8001);

    cout << (int)round(sum / n) 
        << '\n' << input[n / 2]<<'\n';
    int now = 8000;
    if (cnt[now].first == cnt[now - 1].first) {
        while (cnt[now].first == cnt[now - 1].first)now--; now++;
    }
        
    cout << cnt[now].second<<'\n';
    cout << input[n - 1] - input[0];
}