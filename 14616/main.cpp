#include <iostream>
#include <vector>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

struct line {
    double x1;
    double y1;
    double x2;
    double y2;
};

bool comp1(line l1, line l2) {
    return (l1.y2 / l1.x2) < (l2.y2 / l2.x2);
}
bool comp2(line l1, line l2) {
    return min((l1.y1 / l1.x1), (l1.y2 / l1.x2)) < min((l2.y1 / l2.x1), (l2.y2 / l2.x2));
}
int main() {
    int N;
    scanf("%d", &N);
    vector<line> radio;
    for (int i = 0; i < N; i++) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        radio.push_back({ a,b,c,d});
    }

    int M;
    scanf("%d", &M);
    vector<line> razor;
    for (int i = 0; i < M; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        razor.push_back({ 0,0,a,b});
    }

    sort(radio.begin(), radio.end(), comp2);
    sort(razor.begin(), razor.end(), comp1);
    int razor_index = 0;
    int brk_count = 0;
    for (int i = 0; i < N; i++) {
        if (max(radio[i].y2 / radio[i].x2, radio[i].y1 / radio[i].x1) >= razor[razor_index].y2 / razor[razor_index].x2 && min(radio[i].y2 / radio[i].x2, radio[i].y1 / radio[i].x1) <= razor[razor_index].y2 / razor[razor_index].x2) {
            brk_count++;
        }
        else if (min(radio[i].y2 / radio[i].x2, radio[i].y1 / radio[i].x1) > razor[razor_index].y2 / razor[razor_index].x2) {
            if (razor_index == M - 1) break;
            razor_index++;
            i--;
        }
    }
    printf("%d",N- brk_count);

}