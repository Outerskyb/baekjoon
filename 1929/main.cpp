#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

std::set<int> primes;

void getPri(int num)
{
	int *arr;
	arr = (int *)malloc(sizeof(int) * num);
	int i = 2;

	for (i = 2; i <= num; i++) {
		arr[i] = i;
	}

	for (i = 2; i <= sqrt(num); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= num; j += i) {
			arr[j] = 0;
		}
	}

	for (i = 2; i <= num; i++) {
		if (arr[i] != 0) {
			primes.insert(arr[i]);
		}
	}
}

int main(){
    int n,m;
    getPri(1000001);
    cin>>n>>m;
    for(auto it = primes.lower_bound(n); it!=primes.upper_bound(m);it++){
        cout<<(*it)<<'\n';
    }
}