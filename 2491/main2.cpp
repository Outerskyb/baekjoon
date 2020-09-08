#include <iostream>
#include <vector>
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int M = 1;
    int cnt1 = 1;
    int cnt2 = 1;
    for (int i = 1; i < n; i++){
        if (vec[i - 1] < vec[i])
            cnt1 += 1, cnt2 = 1;
        else if (vec[i - 1] == vec[i])
            cnt1 += 1, cnt2 += 1;
        else
            cnt2 += 1, cnt1 = 1;

        M = max(M, cnt1);
        M = max(M, cnt2);
    }
    cout << M;
}