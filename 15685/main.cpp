#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct xy 
{
    int x;
    int y;
};

bool map[101][101];

std::vector<std::vector<xy>> marker;

std::vector<xy> lefter(std::vector<xy> points, int y, int x,bool adjust)
{
    
    int t;
    for (auto& point : points) {
        t = point.y;
        point.y =  point.x;
        point.x = -1 *  t;
    }
    if (adjust) {
        int dx = points[points.size() - 1].x - x;
        int dy = points[points.size() - 1].y - y;
        for (auto& point : points) {
            point.y -= dy;
            point.x -= dx;
        }
    }
    return points;
}

std::vector<xy> dc(int g, int d)
{
    std::vector<xy> output = marker[g - 1];
    std::vector<xy> lefted = lefter(marker[g - 1], output[output.size() - 1].y, output[output.size() - 1].x,true);
    std::reverse(lefted.begin(), lefted.end());
    output.insert(output.end(),lefted.begin(),lefted.end());
    return output;
}

void make_marker() 
{
    std::vector<xy> z;
    z.push_back({ 0,0 });
    z.push_back({ 1,0 });
    marker.push_back(z);
    for (int i = 1; i <= 10; i++) {
        marker.push_back(dc(i, 0));
    }
}

void draw_marker(int g,int d,int y, int x) 
{
    std::vector<xy> mark = marker[g];
    switch(d) {
    case 1:
        mark = lefter(mark, 0, 0,false);
        mark = lefter(mark, 0, 0,false);
        mark = lefter(mark, 0, 0,false);
        break;                  
    case 2:                     
        mark = lefter(mark, 0, 0,false);
        mark = lefter(mark, 0, 0,false);
        break;                  
    case 3:                     
        mark = lefter(mark, 0, 0,false);

    }
    for (auto point : mark) {
        map[point.y + y][point.x + x] = true;
    }
}

int count_corner() 
{
    int count = 0;
    for (int i = 0; i < 100 ; i++) {
        for (int j = 0; j < 100 ; j++) {
            if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) count++;
        }
    }
    return count;
}

void pall(int n = 100) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", map[i][j] );
        }
        printf("\n");
    }
}
int main()
{
    int N, x,y,d,g;
    make_marker();
   /* scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        draw_marker(g, d, y, x);
    }*/
    draw_marker(10, 0, 50, 50);
    draw_marker(10, 1, 50, 50);
    draw_marker(10, 2, 50, 50);
    draw_marker(10, 3, 50, 50);
    pall();
    printf("%d", count_corner());
}