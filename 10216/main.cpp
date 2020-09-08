#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>

#define po(a,b) (a-b)*(a-b)
#define check(a,b) (sqrt(po(ary[a].x,ary[b].x)+po(ary[a].y,ary[b].y))<(ary[a].R+ary[b].R))

using namespace std;

struct triple_pair {
    int x;
    int y; 
    int R;
};

int label[5001];
int pa[5001];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        triple_pair ary[5001];
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", ary[i].x, ary[i].y, ary[i].R);
        }
        int cnt = 1;
        label[0] = cnt;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (check(i, j)) {
                    pa[j] = i;
                }
            }
        }
    }
    return 0;
}