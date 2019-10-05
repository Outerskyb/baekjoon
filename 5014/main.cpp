#include <iostream>

int main() {
    int F, S, G, U, D;
    int now;
    int count = 0;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    now = S;
    int now_max = now;
    while (now != G) {
        if (now < G) {
            if (U == 0) goto use;
            now += U; 
            if (now > now_max) now_max = now;
            else if (now == now_max) goto use;
            count++;
        }
        else if (now > G) {
            if (D == 0) goto use;
            now -= D;
            count++;
        }
    }
    printf("%d", count);
    return 0;

use:
    printf("use the stairs");
    return 0;
}