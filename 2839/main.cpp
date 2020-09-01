#include <iostream>
#include <queue>

using namespace std;

struct s {
	int va;
	int lv;
};

int main()
{
	int n;
	cin >> n;
	if (n == 4 || n == 7) {
		cout << -1;
		return 0;
	}
	else {
		if (n % 5 == 0) {
			cout << n / 5;
		}
		else if (n % 5 == 1) {
			cout << n / 5 + 1;
		}
		else if (n % 5 == 2) {
			cout << n / 5 + 2;
		}
		else if (n % 5 == 3) {
			cout << n / 5 + 1;
		}
		else if (n % 5 == 4) {
			cout << n / 5 + 2;
		}
	}
}