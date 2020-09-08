#include<iostream>

using namespace std;

int main() {
    int N;
    int* input;
    int* visit;
    int* place;
    int max = 0;
    scanf("%d", &N);
    input = (int*)malloc(sizeof(int)*N+2);
    visit = (int*)calloc(N+2, sizeof(int));
    place = (int*)malloc(sizeof(int)*N+2);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
        place[input[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        int search = i;
        int now;
        do {
            now = place[search];
            visit[search] = 1;
            search = (search == N) ? search : ++search;
        } while (now < place[search]);
        if (max < search - i+((search==N)?1:0) ) max = search - i+((search==N)?1:0);
    
    }
    printf("%d", N - max);

}