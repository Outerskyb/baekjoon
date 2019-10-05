#include<iostream>
#include<cstdlib>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int                     main() 
{
    int                 N;
    int**               current_min;
    int**               cost;
   
    scanf("%d", &N);

    current_min = (int**)malloc(sizeof(int*) * N);
    cost  = (int**)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        cost[i] = (int*)malloc(sizeof(int) * 3);
        current_min[i] = (int*)malloc(sizeof(int) * 3);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    current_min[0][0] = cost[0][0];
    current_min[0][1] = cost[0][1];
    current_min[0][2] = cost[0][2];
    
    for (int i = 1; i < N; i++) {
        current_min[i][0] = min(current_min[i - 1][1], current_min[i - 1][2]) + cost[i][0];
        current_min[i][1] = min(current_min[i - 1][0], current_min[i - 1][2]) + cost[i][1];
        current_min[i][2] = min(current_min[i - 1][0], current_min[i - 1][1]) + cost[i][2];
    }
   
    printf("%d", min(current_min[N - 1][0], min(current_min[N - 1][1], current_min[N - 1][2])));
}