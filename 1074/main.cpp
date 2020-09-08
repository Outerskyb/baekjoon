#include <iostream>
#include <map>
#include <cmath>

using namespace std;
int N, r, c;
int cnt;


void dnq(int y, int x, int n, int num) {
	if (n == 1) { printf("%d",num); return; }
	if (r < y + n / 2) {
		if (c < x + n / 2) {
			dnq(y, x, n / 2, num);
		}
		else {
			dnq(y, x + n / 2, n / 2, num + n * n / 4);
		}
	}
	else {
		if (c < x + n / 2) {
			dnq(y + n / 2, x, n / 2, num + n * n / 2);
		}
		else {
			dnq(y + n / 2, x + n / 2, n / 2, num + n * n / 4*3);
		}
	}
}

int main()
{


	cin >> N >> r >> c;

	dnq(0, 0, pow(2, N),0);
}