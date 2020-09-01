#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	
	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		if (x1 == x2 && y1 == y2) {
			cout << ((r1 == r2) ? "-1\n" : "0\n");
		}
		else if (dist == (r1 + r2) * (r1 + r2) || dist == (r1 - r2) * (r1 - r2)) {
			cout << "1\n";
		}
		else if (dist < (r1 + r2) * (r1 + r2) && dist > (r1 - r2) * (r1 - r2)) {
			cout << "2\n";
		}
		else {
			cout << "0\n";
		}
	}
}