#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct ordered_pair {
    int x;
    int y;
    double cos;
};
ordered_pair input[100000];

stack<ordered_pair> stk;
vector<ordered_pair> vec;

bool comp(ordered_pair op1, ordered_pair op2) {
    return op1.cos < op2.cos;
}

double r(ordered_pair op1, ordered_pair op2) {
    return sqrt((op1.x - op2.x)*(op1.x - op2.x) + (op1.y - op2.y)*(op1.y - op2.y));
}

long long int ccw(ordered_pair op1, ordered_pair op2, ordered_pair op3) {
    return (op1.x * op2.y + op2.x * op3.y + op3.x * op1.y) - (op1.x * op3.y + op2.x * op1.y + op3.x * op2.y);
}

int main()
{
    int max_x;
    int max_y = 0;
    int max_idx;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &input[i].x, &input[i].y);
        if (max_y < input[i].y) max_y = input[i].y, max_x = input[i].x, max_idx = i;
    }
    for (int i = 0; i < N; i++) {
        if (i == max_idx) { input[i].cos = -2; continue; }
        input[i].cos = (input[i].x - max_x) / r(input[i], { max_x,max_y,0 });
    }
    sort(input, input + N, comp);

    stk.push(input[1]);
    stk.push(input[2]);
    int next = 3;
    while (next < N) {
        while (stk.size() >= 2) {
            ordered_pair first = stk.top();
            stk.pop();
            ordered_pair second = stk.top();
            if (ccw(second, first, input[next]) > 0) {
                stk.push(first);
                break;
            }
        }
        stk.push(input[next++]);
    }

    while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
    }
    int max = 0;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < N; j++) {
            if (max < (vec[i].x - input[j].x)*(vec[i].x - input[j].x) + (vec[i].y - input[j].y)*(vec[i].y - input[j].y)) max = (vec[i].x - input[j].x)*(vec[i].x - input[j].x) + (vec[i].y - input[j].y)*(vec[i].y - input[j].y);
        }
    }
    printf("%.8lf", sqrt(max));
}