#include <iostream>
#include <vector>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int branch[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    
    int M = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        branch[temp]++;
        M = max(temp, M);
    }
        
    int T, H;
    cin >> T >> H;

    int sum = 0;
    for (int i = M; i > 0; i--) {
        if (branch[i] * i * T > H) {
            sum += H;
        }
        else {
            sum += 
        }
    }
    
}