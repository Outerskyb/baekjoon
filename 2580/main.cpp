#include<iostream>
#include <queue>

using namespace std;

struct point_status {
    int x;
    int y;
    int num;
    int pri;
};

bool operator<(point_status a, point_status b) {
    return a.pri < b.pri;
}

int map[9][9];

priority_queue<point_status> a;

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &map[i][j]);
    f

}