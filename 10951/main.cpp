#include <iostream>

using namespace std;

int main()
{
	int a, b;
	while (EOF != scanf("%d %d", &a, &b)) {
		cout << a + b << '\n';
	}
}