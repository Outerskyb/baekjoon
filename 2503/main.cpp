#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool k[1000];

int main()
{
	int N;
	memset(k, 1, 1000);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (b == 1) {
			for (int j = 111; j < 1000; j++) {
				if ((j % 10 != a % 10) 
				&& ((j / 10) % 10 != (a / 10) % 10)
				&& (j / 100 != a / 100)) k[j] = true;
			}
		}
		else if (b == 2) {
			for (int j = 111; j < 1000; j++) {
				if ((j % 10 != a % 10)
					&& ((j / 10) % 10 != (a / 10) % 10)
					&& (j / 100 != a / 100)) k[j] = true;
			}
		}
		else if (b == 3) {
			cout << 1;
			return 0;
		}
	}
}