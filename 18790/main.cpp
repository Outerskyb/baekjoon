#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < 2 * N + 1; i++) 
    {
        int temp;
        cin >> temp;
        vec[temp]++;
    }

    for (int i = 1; i < N/2; i++) {
        if (vec[i] >= N) {

        }
    }
}