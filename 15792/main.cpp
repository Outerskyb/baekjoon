#include <iostream>

using namespace std;

int main() 
{
    int A, B;
    cin >> A >> B;
    cout << A / B;
    int cnt = 0;
    if (A % B) cout << '.';
    while(A % B) {
        A -= A / B * B;
        A *= 10;
        cout << A / B;
        cnt++;
        if (cnt > 1050) break;
    }
}