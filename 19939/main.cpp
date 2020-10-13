#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    if(n<k*(k+1)/2)
        cout << -1;
    else
        cout << k-1+((n-k*(k+1)/2)%k!=0);
}