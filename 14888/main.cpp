#include <iostream>
#include <vector>
#include <algorithm>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num;
    vector<int> op;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            op.push_back(i);
        }
    }

    int m=987654321, M=-987654321;
    do {
        int sum = num[0];
        for (int i = 1; i < n; i++) {
            if (op[i - 1] == 0) sum += num[i];
            if (op[i - 1] == 1) sum -= num[i];
            if (op[i - 1] == 2) sum *= num[i];
            if (op[i - 1] == 3) sum /= num[i];
        }
        m = min(m, sum);
        M = max(M, sum);
    } while (next_permutation(op.begin(), op.end()));

    cout << M << '\n' << m;
}