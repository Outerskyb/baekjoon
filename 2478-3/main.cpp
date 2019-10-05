#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int a1,a2,a3;
    vector<int> inputs;
    vector<int> diff;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        inputs.push_back(temp);
    }

    diff.push_back(abs(inputs[0] - inputs[N - 1]));
    for (int i = 1; i < N ; i++) {
        diff.push_back(abs(inputs[i] - inputs[i - 1]));
    }
   

    for (int i = 0; i < N - 1; i++) {
        if (diff[i] != 1) {
            a3 = i;
            rotate(inputs.begin(), inputs.begin() + i, inputs.end());
            rotate(diff.begin(), diff.begin() + i, diff.end());
            break;
        }
    }

    int* v = new int[N];
    for (int i = 0; i < N; i++) v[i] = -1;
    int point, point2;
    for (int i = 0; i < N; i++) {
        if (diff[i]==1) continue;
        if (v[diff[i]] >= 0) point = v[diff[i]], point2 = i;
        else v[diff[i]] = i;
    }

    reverse(inputs.begin() + point, inputs.begin() + point2);
    a2 = point, a1 = point2 - 1;

    for (int i = 0; i < N - 1; i++) {
        if (inputs[i] > inputs[i + 1]) {
            printf("%d", i + 1);
            rotate(inputs.begin(), inputs.begin() + i+1, inputs.end());
            printf("\n%d %d\n", a2, a1);
            printf("%d", a3);
            return 0;
        }
    }


}