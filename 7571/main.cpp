#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct ordered_pair {
    int x;
    int y;
};
int N, M;
vector<ordered_pair> points;
int ans = 987654321;
bool** visit;

bool cmp1(ordered_pair op1, ordered_pair op2) {
    return op1.x < op2.x;
}

bool cmp2(ordered_pair op1, ordered_pair op2) {
    return op1.y < op2.y;
}

int get_dist(ordered_pair comp) {
    visit[comp.x][comp.y] = 1;
    int dist = 0;
    for (int i = 0; i < points.size(); i++) {
        dist += abs(comp.x - points[i].x) + abs(comp.y - points[i].y);
    }
    if (dist < ans) ans = dist;
    return dist;
}

void search(ordered_pair comp, int way) {
    int center = get_dist(comp);
    if ((way == 9 || (way == 7 || way == 1 || way == 0)) && visit[comp.x + 0][comp.y - 1] != 1 && comp.y != 1 && center > get_dist({ comp.x + 0,comp.y - 1 }))  search({ comp.x + 0,comp.y - 1 }, 0);
    if ((way == 9 || way == 1) && visit[comp.x + 1][comp.y - 1] != 1 && comp.x != N && comp.y != 1 && center > get_dist({ comp.x + 1,comp.y - 1 }))  search({ comp.x + 1,comp.y - 1 }, 1);
    if ((way == 9 || (way == 1 || way == 2 || way == 3)) && visit[comp.x + 1][comp.y + 0] != 1 && comp.x != N && center > get_dist({ comp.x + 1,comp.y + 0 }))  search({ comp.x + 1,comp.y + 0 }, 2);
    if ((way == 9 || way == 3) && visit[comp.x + 1][comp.y + 1] != 1 && comp.x != N && comp.y != N && center > get_dist({ comp.x + 1,comp.y + 1 }))  search({ comp.x + 1,comp.y + 1 }, 3);
    if ((way == 9 || (way == 3 || way == 4 || way == 5)) && visit[comp.x + 0][comp.y + 1] != 1 && comp.y != N && center > get_dist({ comp.x + 0,comp.y + 1 }))  search({ comp.x + 0,comp.y + 1 }, 4);
    if ((way == 9 || way == 5) && visit[comp.x - 1][comp.y + 1] != 1 && comp.x != 1 && comp.y != N && center > get_dist({ comp.x - 1,comp.y + 1 }))  search({ comp.x - 1,comp.y + 1 }, 5);
    if ((way == 9 || (way == 5 || way == 6 || way == 7)) && visit[comp.x - 1][comp.y + 0] != 1 && comp.x != 1 && center > get_dist({ comp.x - 1,comp.y + 0 }))  search({ comp.x - 1,comp.y + 0 }, 6);
    if ((way == 9 || way == 7) && visit[comp.x - 1][comp.y - 1] != 1 && comp.x != 1 && comp.y != 1 && center > get_dist({ comp.x - 1,comp.y - 1 }))  search({ comp.x - 1,comp.y - 1 }, 7);
}

int main() {
    scanf("%d %d", &N, &M);
    visit = (bool**)malloc(sizeof(bool*)*(N + 3));
    for (int i = 0; i < N + 3; i++) {
        visit[i] = (bool*)calloc((N + 3), sizeof(bool));
    }
    int X = 0, Y = 0;
    int x, y;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        X += x;
        Y += y;
        points.push_back({ x,y });
    }
    nth_element(points.begin(),points.begin()+points.size()/2, points.end(), cmp2);
    get_dist(points[M / 2-((M%2==0)?0:1)]);
    printf("%d", ans);

    return 0;
}


/*--------------TEST CASE---------------
input
6 3
1 1
1 2
1 6

output
5


*/