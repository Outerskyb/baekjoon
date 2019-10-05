#include<iostream>

using namespace std;

int main() {
    int w, h, t;
    int x, y;
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);

    printf("%d %d", (((t + x) / w) % 2 == 0) ? (t + x) % w : w - (t + x) % w, (((t + y) / h) % 2 == 0) ? (t + y) % h : h - (t + y) % h);

}