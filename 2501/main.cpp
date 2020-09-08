#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n , k;
    cin >> n >> k;

    vector<int> divisors;

    for(int i = 1 ; i <= sqrt(n);i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(i*i != n) divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(),divisors.end());
    if(divisors.size()<k) cout << 0;
    else   cout<<divisors[k];
}