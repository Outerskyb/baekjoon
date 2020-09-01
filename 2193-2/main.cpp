#include <iostream>
#include <cinttypes>
using namespace std;
/*
1
10
100
101
1000
1001
1010
10000
10001
10010
10100
10101
an bn
an 0 1 1 2 3
bn 1 0 1 2 3
an+1 = an + bn
bn+1 = an
*/
int main() 
{
	uint64_t n;
	cin >> n;
	uint64_t a[91];
	uint64_t b[91];
	b[0] = 1; b[1] = 0; b[2] = 1;
	a[0] = 0, a[1] = 1, a[2] = 1;
	for (uint64_t i = 3; i <= 90; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = a[i - 1];
	}

	cout << a[n-1] + b[n-1];
}