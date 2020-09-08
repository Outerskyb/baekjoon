#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<string> vec;
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        vec.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--) {
            cout << vec[i][j];
        }
        cout << '\n';
    }
}