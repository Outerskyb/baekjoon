#include <iostream>

using namespace std;

int64_t mul(int64_t a, int64_t b, int64_t c) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2) {
		int64_t root = mul(a, b / 2, c);
		return (a*(root*root%c)) % c;
	}
	else {
		int64_t root = mul(a, b / 2, c);
		return (root*root) % c;
	}
}

int main()
{
	int64_t a, b, c;
	cin >> a >> b >> c;
	printf("%d", mul(a, b, c));
}

int64_t fact(int64_t a, int64_t b)
{
	if (b == 0) return 1;
	if (b == 1) return a;

	if (b % 2 == 0) {
		return (fact(a, b / 2)  * fact(a, b / 2)) % C;
	}
	else {
		return (a * (fact(a, b / 2) * fact(a, b / 2) % C)) % C;
	}
}

