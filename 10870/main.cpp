#include <iostream>
#include <cinttypes>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	int prev = 1;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int temp = now;
		now += prev;
		prev = temp;
	}
	cout << now;
}