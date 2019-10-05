#include <iostream>
#include <cinttypes>

using namespace std;
int a, b, c;
int64_t exp(int64_t a, int64_t b) 
{
	if (b == 0) return 1;
	if (b == 1) return a;
	int64_t h = exp(a, b / 2);
	if (b % 2) {
		return (a * ((h * h)%c))%c;
	}
	else {
		return (h*h)%c;
	}
}

int main()
{
	
	cin >> a >> b >> c;
	cout << exp(a, b) % c;
}