#include <iostream>

using namespace std;

int main()
{
	int l, p, v;
	
	int cse = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		cout << "Case " << cse++ << ": " << v / p * l + (((v % p)>l)?l:(v%p)) << '\n';
	}
}