#include<iostream>

using namespace std;

int map[10][10] = { {46, 18, 22, 27, 31, 36, 40, 45,  4,  9},
                    {18, 47, 27, 31, 36, 40, 45,  4,  9, 13},
                    {22, 27, 48, 36, 40, 45,  4,  9, 13, 18},
                    {27, 31, 36, 49, 45,  4,  9, 13, 18, 22},
                    {31, 36, 40, 45, 50,  9, 13, 18, 22, 27},
                    {36, 40, 45,  4,  9, 51, 18, 22, 27, 31},
                    {40, 45,  4,  9, 13, 18, 52, 27, 31, 36},
                    {45,  4,  9, 13, 18, 22, 27, 53, 36, 40},
                    { 4,  9, 13, 18, 22, 27, 31, 36, 54, 45},
                    { 9, 13, 18, 22, 27, 31, 36, 40, 45, 55} };

int main() {
    int a,  b;
    scanf("%d %d",  &a,  &b);
    printf("%.3f", map[a][b] / 55.0);
}