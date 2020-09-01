#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		
		cin >> a >> b;
		int mul = a * b;
		while (b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		cout << mul/a << '\n';
	}
}