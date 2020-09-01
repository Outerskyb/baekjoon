#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int A = 0, B = 0;
	A += 100 * (a % 10), a /= 10, A += 10 * (a % 10), a /= 10, A += a;
	B += 100 * (b % 10), b /= 10, B += 10 * (b % 10), b /= 10, B += b;

	cout << ((A > B) ? A : B);
}