#include<iostream>

using namespace std;

int N;
int ary[100000];

int main() {
    int count = 1, max = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ary[i]);
        if (i != 0 && ary[i] >= ary[i - 1]) count++;
        else { if (count > max) max = count; count = 1; }
    }
    for (int i = 0; i < N; i++) {
        if (i != 0 && ary[i] <= ary[i - 1]) count++;
        else { if (count > max) max = count; count = 1; }
    }
    printf("%d", max);

}