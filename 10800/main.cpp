#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp1(pair<int,int> p1, pair<int,int> p2) {
    return (p1.second < p2.second);
}

int main() {
    int N;
    scanf("%d", &N);
   pair<int,int> input[200000];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &input[i].first, &input[i].second);
    }
    sort(input,input + N-1, comp1);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; input[j].second <= input[i].second; j++) {
            if (input[j].first != input[i].first) {
                sum += input[j].second;
            }
        }
        printf("%d", sum);
    }
}

