#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int prev = 0;
	int curr = 1;
	int now = 1;
	for (int i = 0; i < n-1; i++) {
		now = curr + prev;
		prev = curr;
		curr = now;
	}
	cout << now;
}