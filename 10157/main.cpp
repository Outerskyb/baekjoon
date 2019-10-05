#include <iostream>

using namespace std;

int main() {
    int C, R, K;
    int ap=0;
    int x = 1; int y = 1;
    int turn = 0;
    scanf("%d %d %d", &C, &R, &K);
    int w1, w2, h1, h2;
    h1 = h2 = R;
    w1 = C;
    w2 = w1 - 1;
    if (K > C*R) {
        printf("0");
        return 0;
    }
    while (K > 1) {
        switch (turn) {
        case 0:
            K -= h1-1, y += h1-1;
            if (ap == 0) h1 = h1 - 1,ap=1;
            else h1 -= 2;
            turn++;
            break;
        case 1:
            K -= w1-1, x += w1 - 1;
            w1 -= 2;
            turn++;
            break;
        case 2:
            K -= h2-1, y -= h2 - 1;
            h2 -= 2;
            turn++;
            break;
        case 3:
            K -= w2-1, x -= w2 - 1;
            w2 -= 2;
            turn = 0;
            break;
        }
    }
    if (K == 1) {
        K = 0;
    }
    else  {
        K--;
    }
    
    switch (turn) {
    case 0:
        x -= K;
        break;
    case 1:
        y += K;
        break;
    case 2:
        x += K;
        break;
    case 3:
        y -= K;
        break;
    }
    printf("%d %d", x, y);
}