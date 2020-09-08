#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n + 1);
	vec[0] = 1;
	vec[1] = 0;
	vec[2] = 3;
	vec[3] = 0;
	vec[4] = 11;

	for (int i = 5; i <= n; i++) {
		vec[i] = vec[i - 2] * 3;
		if (i % 2) vec[i] = 0;
		else
			for (int j = 4; j <= i; j += 2) {
				vec[i] += 2 * vec[i - j];
			}
	}
	cout << vec[n];
}