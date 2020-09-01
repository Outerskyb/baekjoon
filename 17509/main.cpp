#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int D[11],sum=0;
	for (int i = 0; i < 11; i++) {
		int v;
		cin >> D[i] >> v;
		sum += 20 * v;
	}
	
	sort(D, D + 11);
	int t = 0;
	for (int i = 0; i < 11; i++) {
		sum += D[i]+t;
		t = D[i]+t;
	}
	cout << sum;
}