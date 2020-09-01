#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int pprev = 2;
	int prev = 3;
	int ans = 4;
	if (n == 1)		 ans = 1;
	else if (n == 2) ans = 2;
	else if (n == 3) ans = 3;
	
	for (int i = 4; i <= n; i++) {
		ans = (pprev % 10 + prev % 10) % 10;
		pprev = prev;
		prev = ans;
	}
	cout << ans;
}
