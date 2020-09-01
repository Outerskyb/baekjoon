#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<uint64_t> vec(101);

	vec[1] = 1, vec[2] = 1, vec[3] = 1, vec[4] = 2, vec[5] = 2;

	for (int i = 6; i <= 100; i++) vec[i] = vec[i - 1] + vec[i - 5];

	while (T--) {
		int a;
		cin >> a;
		cout << vec[a]<<'\n';
	}
}