#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;
	for (int i = 0; i < 4473; i++) {
		vec.push_back(i * (i + 1) / 2);
		if (i * (i + 1) / 2 > 10000000) break;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (n <= vec[i]) {
			if (i % 2)
				cout << i - (n - vec[i - 1]) + 1 << '/' << (n - vec[i - 1]);
			else
				cout << (n - vec[i - 1]) << '/' << i - (n - vec[i - 1]) + 1;
			break;
		}
	}
}