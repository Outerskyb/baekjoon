#include<iostream>
#include<string>
#include<vector>

#define aToi(x) x-'0'

using namespace std;

bool thirty_four[10][10] = { {1,1,1,1,1,1,1,1,1,1},{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{1,1,1,0,}, };

template <int N>constexpr int fibonazzi() { return fibonazzi<N - 1>() + fibonazzi<N - 2>(); }
template <> constexpr int fibonazzi<1>() { return 1; }
template <> constexpr int fibonazzi<0>() { return 1; }

template <int N> class fibo {
public:
    fibo<N - 1> rest_of_the_data;
    int operator [] (int i) const
    {
        return *((int *)this + i);
    }
    int num;
    fibo() : num(fibonazzi<N>()) {};
};
template <> class fibo<0> {
public:
    int num;
    fibo<0>() : num(fibonazzi<0>()) {};
};

int main() {
    string str;
    vector<int> ary;

    cin >> str;
    char prev, now;
    int  length = 0;
    int ans = 1;
    prev = '0';
    for (int i = 0; i < str.size(); i++) {
        now = str[i];
        if (now == '0') {
            if (aToi(prev) > 4) {
                printf("0");
                return 0;
            }
            ary.push_back(length - 1);
            length = 0;
            prev = now;
            continue;
        }
        if (!thirty_four[aToi(prev)][aToi(now)]) {
            ary.push_back(length);
            length = 1;
            prev = now;
            continue;
        }
        prev = now;
        length++;
    }
    ary.push_back(length);

    const fibo<40> fiboo;

    for (int i = 0; i < ary.size(); i++) {
        ans *= fiboo[ary[i]];
    }
    printf("%d", ans);
}