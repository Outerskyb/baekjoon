#include <iostream>
#include <chrono>
#define swap(a,b,temp) temp=a; a=b; b=temp;

int position[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
int count = 0;
int N;

inline bool check(int last) {
    for (int i = 0; i < last; i++) {
        for (int j = i; j < last; j++) {
            if (((i + position[i]) == (j + position[j]) || (i - position[i]) == (j - position[j])) && j != i) {
                return false;
            }
        }
    }
    return true;
}

void permutations(int *position, const int k)
{
    if (!check(k)) return;
    int i;
    int temp;
    if (k == N - 1) {
        if (check(N)) {
            count++;
            /*for (int i = 0; i < N; i++) {
                printf("%d", position[i]);
            }
            printf("\n");*/
        }
    }
    else {
        for (i = k; i <= N - 1; i++) {
            swap(position[k], position[i], temp);
            permutations(position, k + 1);
            swap(position[k], position[i], temp);
        }
    }
}
int main()
{
    scanf("%d", &N);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    permutations(position, 0);

    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    std::chrono::duration<double> sec = end - start;
    
    printf("%d %lf", count,sec);
}