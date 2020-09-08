#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct op
{
    int first;
    int second;
    int index;
};

bool comp1(op p1, op p2) {
    return (p1.second < p2.second);
}

int main() {
    int N;
    scanf("%d", &N);
    int answer[200000] = { 0, };
    op input[200000];
    int colors[200000] = { 0, };
    
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &input[i].first, &input[i].second);
        input[i].index = i;
    }
    sort(input, input + N , comp1);
    int sum = 0;
    for (int i = 0,j = 0; i < N; i++) {
        for (;  input[j].second < input[i].second; j++) {
            sum += input[j].second;
            colors[input[j].first] += input[j].second;
        }
        answer[input[i].index] = sum - colors[input[i].first];
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", answer[i]);
    }
}