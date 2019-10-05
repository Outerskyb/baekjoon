#include <iostream>
#include <vector>

#define min(a,b) (((a)>(b))?(b):(a))

using namespace std;

struct line {
    int x1;
    int x2;
    int y1;
    int y2;
    int w;
};

bool comp(line l1, line l2) {
    uint64_t f1 = (l1.x1*l1.y2 - l1.x2*l1.y1) + (l1.x2*l2.y1 - l2.x1*l1.y2) + (l2.x1*l1.y1 - l1.x1*l2.y1);
    uint64_t f2 = (l1.x1*l1.y2 - l1.x2*l1.y1) + (l1.x2*l2.y2 - l2.x2*l1.y2) + (l2.x2*l1.y1 - l1.x1*l2.y2);
    return f1 * f2 < 0;
}

int main() 
{
    std::vector<line> vec;
    int L;
    int way = 0;
    int N;
    int time = 0;

    int cur_x = 0, cur_y = 0;
    scanf("%d %d", &L, &N);
    for (int i = 0; i < N; i++) {
        int t; char dir;
        scanf("%d %c", &t, &dir);

        int next_x=cur_x, next_y = cur_y;

        if (way == 0) {
            next_x = cur_x + t;
        }
        else if (way == 1) {
            next_y = cur_y - t;
        }
        else if (way == 2) {
            next_x = cur_x - t;
        }
        else if (way == 3) {
            next_y = cur_y + t;
        }
        vec.push_back({ next_x,cur_x,next_y,cur_y,way });
        line last = vec[vec.size() - 1];
        for (int i = 0; i < vec.size()-1; i++) {
            if (!comp(last, vec[i])) {
                int more;
                switch (way)
                {
                case 0:
                    more = min(vec[i].x1 - cur_x, vec[i].x2 - cur_x);
                    break;
                case 1:
                    more = min(cur_y - vec[i].y1, cur_y - vec[i].y2);
                    break;
                case 2:
                    more = min(cur_x - vec[i].x1, cur_x - vec[i].x2);
                    break;
                case 3:
                    more = min(vec[i].y1 - cur_y, vec[i].y2 - cur_y);
                    break;
                default:
                    break;
                }
                printf("%d", time + more);
                return 0;
            }
        }

        if (dir == 'L') way = (way + 1) % 4;
        else way = (way - 1) % 4;
        time += t;
    }
}