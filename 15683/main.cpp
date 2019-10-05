#include <iostream>
#define max(a,b) (((a)>(b))? (a):(b))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
using namespace std;

const int state[5] = { 4,2,4,4,1 };

int main() 
{
    int N, M;
    int map[8][8] = { {0,} };
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int sum = 0;
    int R, L, U, D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            switch (map[i][j]) {
            case 1:
                R = 0;
                for (int x = j; x < M; x++, R++) {
                    if (map[i][x] == 6) break;
                }
                L = 0;
                for (int x = j; x >= 0; x--, L++) {
                    if (map[i][x] == 6) break;
                }
                D = 0;
                for (int y = i; y < N; y++, D++) {
                    if (map[y][j] == 6) break;
                }
                U = 0;
                for (int y = i; y >= 0; y--, U++) {
                    if (map[y][j] == 6) break;
                }
                sum += max4(R, L, D, U);
                break;
            case 2:
                R = 0;
                for (int x = j; x < M; x++, R++) {
                    if (map[i][x] == 6) break;
                }
                L = 0;
                for (int x = j; x >= 0; x--, L++) {
                    if (map[i][x] == 6) break;
                }
                D = 0;
                for (int y = i; y < N; y++, D++) {
                    if (map[y][j] == 6) break;
                }
                U = 0;
                for (int y = i; y >= 0; y--, U++) {
                    if (map[y][j] == 6) break;
                }
                sum += max(U + D, L + R);
                break;
            case 3:
                R = 0;
                for (int x = j; x < M; x++, R++) {
                    if (map[i][x] == 6) break;
                }
                L = 0;
                for (int x = j; x >= 0; x--, L++) {
                    if (map[i][x] == 6) break;
                }
                D = 0;
                for (int y = i; y < N; y++, D++) {
                    if (map[y][j] == 6) break;
                }
                U = 0;
                for (int y = i; y >= 0; y--, U++) {
                    if (map[y][j] == 6) break;
                }
                sum += max4(U + R, R + D, D + L, L + U);
                break;
            case 4:
                R = 0;
                for (int x = j; x < M; x++, R++) {
                    if (map[i][x] == 6) break;
                }
                L = 0;
                for (int x = j; x >= 0; x--, L++) {
                    if (map[i][x] == 6) break;
                }
                D = 0;
                for (int y = i; y < N; y++, D++) {
                    if (map[y][j] == 6) break;
                }
                U = 0;
                for (int y = i; y >= 0; y--, U++) {
                    if (map[y][j] == 6) break;
                }
                sum += max4(L + U + R, U + R + D, R + D + L, D + L + U);
                break;
            case 5:
                R = 0;
                for (int x = j; x < M; x++, R++) {
                    if (map[i][x] == 6) break;
                }
                L = 0;
                for (int x = j; x >= 0; x--, L++) {
                    if (map[i][x] == 6) break;
                }
                D = 0;
                for (int y = i; y < N; y++, D++) {
                    if (map[y][j] == 6) break;
                }
                U = 0;
                for (int y = i; y >= 0; y--, U++) {
                    if (map[y][j] == 6) break;
                }
                sum += (R+L+U+D);
                break;
            default:

                break;
            }
      }
    }
    
}