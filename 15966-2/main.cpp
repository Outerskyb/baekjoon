#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100000];
    int check[1000001] = { 0 };

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    check[arr[0]] = 1;
    int M = 0;
    for (int i = 0; i < n; i++) {
        if (check[arr[i] - 1]) ++check[arr[i]], M = max(M, check[i]);
        else check[arr[i]] = 1;
    }
    
    cout << M;
}