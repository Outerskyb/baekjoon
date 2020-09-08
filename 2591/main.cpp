#include<iostream>
#include<string>
#include<vector>
using namespace std;

using u64 = unsigned long long int;

u64 fibo[41];

void get_fibo() {
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < 41; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main() {
    string str;
    vector<int> ary;

    cin >> str;
    char prev, now;
    int  count = 0;
    int ans = 1;
    prev = '0';
    for (int i = 0; i < str.size(); i++) {
        now = str[i];
        if (now == '0') {
            if ((prev - '0') * 10 + (now - '0') > 34) {
                printf("0");
                return 0;
            }
            ary.push_back(count - 1);
            count = 0;
            prev = now;
            continue;
        }
        if ((prev - '0') * 10 + (now - '0') > 34) {
            ary.push_back(count);
            count = 1;
            prev = now;
            continue;
        }
        prev = now;
        count++;
    }
    ary.push_back(count);
    get_fibo();
    
    for (int i = 0; i < ary.size(); i++) {
        ans*=fibo[ary[i]];
    }
    printf("%d", ans);
    

    
}