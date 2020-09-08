#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> vec;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    vector<int> points;
    for (int i = 0; i < N-1; i++) {
        if (vec[i] + 1 != vec[i + 1] && vec[i] - 1 != vec[i + 1]) points.push_back(i);
    }

    printf("%d\n%d %d\n", points[0] + 1, points[1] - points[0] + 1, points[2] - points[0] + 1);
    for (int i = 0; i < N-1; i++) {
        if (vec[i] + 1 != vec[i + 1]) points.push_back(i);
    }
    printf("%d", points[points.size() - 1]);
}