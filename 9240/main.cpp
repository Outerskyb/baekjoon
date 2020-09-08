#include <iostream>
#include <cmath>
struct ordered_pair {
    int x;
    int y;
};

ordered_pair input[100000];

int main() 
{
    int C;
    double max = 0;
    int center_x = 0, center_y = 0;
    int far_x = 0, far_y = 0;
    int second_x = 0, second_y = 0;
    scanf("%d", &C);
    if (C < 10000) {
        for (int i = 0; i < C; i++) {
            scanf("%d %d", &input[i].x, &input[i].y);
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < C; j++) {
                if (max < ((input[j].x - input[i].x)*(input[j].x - input[i].x) + (input[j].y - input[i].y)*(input[j].y - input[i].y))) {
                    max = (input[j].x - input[i].x)*(input[j].x - input[i].x) + (input[j].y - input[i].y)*(input[j].y - input[i].y);
                }
            }
        }
        printf("%.8lf", sqrt(max));
    }
    else {
        for (int i = 0; i < C; i++) {
            scanf("%d %d", &input[i].x, &input[i].y);
            center_x += input[i].x;
            center_y += input[i].y;
        }
        center_x /= C;
        center_y /= C;
        for (int i = 0; i < C; i++) {
            if (max < ((center_x - input[i].x)*(center_x - input[i].x) + (center_y - input[i].y)*(center_y - input[i].y))) {
                max = (center_x - input[i].x)*(center_x - input[i].x) + (center_y - input[i].y)*(center_y - input[i].y);
                second_x = far_x;
                second_y = far_y;
                far_x = input[i].x;
                far_y = input[i].y;
            }
        }

        max = 0;
        for (int i = 0; i < C; i++) {
            if (max < ((far_x - input[i].x)*(far_x - input[i].x) + (far_y - input[i].y)*(far_y - input[i].y))) {
                max = (far_x - input[i].x)*(far_x - input[i].x) + (far_y - input[i].y)*(far_y - input[i].y);
            }
        }

        printf("%.8lf", sqrt(max));
    }
}