#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vector<int> vec1, vec2, vec3, vec4;
    for (int i = 0; i < N; i++) {
        if (vec[i] < 0 && i % 2)  vec3.push_back(vec[i]);
        else if (vec[i] < 0) vec4.push_back(vec[i]);
        else if (i % 2) vec1.push_back(vec[i]);
        else vec2.push_back(vec[i]);
    }
    if (vec3.size()!=0&&vec1[0] < vec2[0]) {
        if (vec4[vec4.size() - 1] > vec3[vec3.size() - 1]) {
            for (auto it = vec3.rbegin(); it != vec3.rend(); ++it) cout << *it << ' ';
            for (auto el : vec4) cout << el << ' ';
        }
        else {
            for (auto it = vec4.rbegin(); it != vec4.rend(); ++it) cout << *it << ' ';
            for (auto el : vec3) cout << el << ' ';
        }
    }
    else if (vec4.size() != 0) cout << vec4[0] << ' ';
    for (auto& el : vec1) cout << el << ' ';
    for (auto it = vec2.rbegin(); it != vec2.rend(); ++it) {
        cout << *it << ' ';
    }
    if (vec3.size() != 0 && vec1[0] > vec2[0]) {
        if (vec4[vec4.size() - 1] > vec3[vec3.size() - 1]) {
            for (auto it = vec4.rbegin(); it != vec4.rend(); ++it) cout << *it << ' ';
            for (auto el : vec3) cout << el << ' ';
        }
        else {
            for (auto it = vec3.rbegin(); it != vec3.rend(); ++it) cout << *it << ' ';
            for (auto el : vec4) cout << el << ' ';
        }
    }
    else if (vec4.size() != 0) cout << vec4[0] << ' ';
}