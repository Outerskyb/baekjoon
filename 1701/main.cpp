#include<iostream>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int source[20000];
        int destination[20000];
        int V, E;
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; i++) {
            scanf("%d %d", source[i], destination[i]);
        }
        for (int i = 0; i < E; i++) {
            if (source[i] > destination[i]) {
                int temp = source[i];
                source[i] = destination[i];
                destination[i] = temp;
            }
        }
    }
}