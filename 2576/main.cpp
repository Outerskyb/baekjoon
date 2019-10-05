#include<iostream>

using namespace std;

int main() {
    int a[7];
    int sum = 0;
    int min = 999999;

    for (int i = 0; i < 7; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1) {
            sum += a[i];
            if (min>a[i]) min = a[i];
        }
    }
    if (sum == 0) {
        cout << -1;
        return 0;
    }
    cout << sum << endl << min;
}