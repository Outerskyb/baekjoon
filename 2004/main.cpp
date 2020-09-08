#include <iostream>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int cnt = 0;
	int cnt2 = 0;
	for (int i = 5; n / i >= 1; i *= 5)
		cnt += n / i;
	for (int i = 5; (n - m+1) / i >= 1; i *= 5)
		cnt2 += (n - m) / i;

	int cnt3 = 0;
	for (int i = 5; m / i >= 1; i *= 5)
		cnt3 += m / i;

	cout << (cnt - cnt2) - cnt3;
}