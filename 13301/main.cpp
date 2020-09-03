#include <iostream>
#include <vector>
#include <cinttypes>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<uint64_t> f(81);
	f[0] = 0, f[1] = 1;
	for (int i = 2; i <= 80; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	if (n == 1)
		cout << 4;
	else if (n == 2)
		cout << 6;
	else if (n == 3)
		cout << 10;
	else
		cout << f[n] * 3 + f[n - 1] * 2 + f[n - 2] * 2 + f[n - 3];
}