#include <iostream>
#include <vector>
#include <string>

using namespace std;

uint64_t fibo[5001] = { 1, 1, 2 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s[0] == '0') { cout << 0; return 0; }
    for (int i = 3; i < 5001; i++) {
        fibo[i] = (fibo[i - 1] % 1000000 + fibo[i - 2] % 1000000) % 1000000;
    }

    vector<int> nums;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 != s.size() && s[i] > '2' && s[i + 1] == '0') {
            cout << 0; return 0;
        }
        else if (i + 1 != s.size() && s[i + 1] == '0') {
            if(s[i]=='0') { cout << 0; return 0; }
            nums.push_back(cnt);
            i++;
            cnt = 0;
        }
        else if (s[i] - '0' > 2 || (s[i] - '0' >= 2 && s[i + 1] - '0' > 6)) {
            nums.push_back( cnt + 1);
            cnt = 0;
        }
        else {
            cnt++;
            if (i == s.size() - 1)
                nums.push_back( cnt);
        }
    }

    uint64_t ans = 1;
    for (const auto el : nums) {
        ans = ((ans % 1000000) * (fibo[el] % 1000000)) % 1000000;
    }
    cout << ans % 1000000;
}
