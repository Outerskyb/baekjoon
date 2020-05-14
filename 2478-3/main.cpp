#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int a1, a2, a3;
    vector<int> inputs;
    vector<int> diff;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        inputs.push_back(temp);
    }

    diff.push_back(inputs[0] - inputs[N - 1]);
    for (int i = 1; i < N; i++) {
        diff.push_back(inputs[i] - inputs[i - 1]);
    }


    for (int i = 0; i < N - 1; i++) {
        if (diff[i] != 1) {
            a3 = N-i;
            rotate(inputs.rbegin(), inputs.rbegin() + N - i, inputs.rend());
            rotate(diff.rbegin(), diff.rbegin() + N - i, diff.rend());
            break;
        }
    }


    int point = 0, point2 = 0;
    for (int i = 0; i < N; i++) {
        if (point < 0 && diff[i] < 0) point = i;
        if (diff[i] < 0) point2 = i;
    }

    reverse(inputs.begin() + point, inputs.begin() + point2);
    a2 = point, a1 = point2 - 1;

    for (int i = 0; i < N - 1; i++) {
        if (inputs[i] > inputs[i + 1]) {
            printf("%d", N - i - 1);
            rotate(inputs.rbegin(), inputs.rbegin() + N - i - 1, inputs.rend());
            printf("\n%d %d\n", a2 , a1 );
            printf("%d", a3);
            return 0;
        }
    }


}