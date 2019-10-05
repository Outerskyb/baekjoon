#include <iostream>

using namespace std;

int main()
{
    int n;
    int d[1000][1000] = { {0,} };
    int p, q;
    int spot_pos[1000];
    int spot_exp[1000];
    int hotel_pos[1000];
    int hotel_exp[1000];

    scanf("%d", &n);
    for (int i = 0; i < n*n; i++) {
        scanf("%d", &d[i / n][i%n]);
    }
    scanf("%d %d", p, q);
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &spot_pos[i], &spot_exp[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &hotel_pos[i], &hotel_exp[i]);
    }

    //calc distance with Dijkstra
    
}