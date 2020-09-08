#include<iostream>
#include<vector>
#include<algorithm>

using pair = std::pair<int, int>;

bool comp1(pair a, pair b) {
    return a.first < b.first;
}

bool comp2(pair a, pair b) {
    return a.second < b.second;
}

int main() {
    int N;
    scanf_s("%d", &N);
    std::vector<pair> vec(N);
    
    for (int i = 0; i < N; i++) {
        scanf_s("%d %d", &vec[i].first, &vec[i].second);
    }

    std::sort(vec.begin(), vec.end(),comp2);
    std::stable_sort(vec.begin(), vec.end(), comp1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
    scanf_s("%d", &N);
}