#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int mul = a * b;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	cout << a << '\n' << mul / a;
}