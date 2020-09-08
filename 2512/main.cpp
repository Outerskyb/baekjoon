#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	vector<int> vec;
	int sum=0, max=0;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp); vec.push_back(temp); 
		if (temp > max) max = temp;
		sum += temp;
	}
	cin >> m;
	if (sum <= m) {
		printf("%d", max);
		return 0;
	}
	int st = 0;
	int end = m;

	while (st+1  < end) {
		int mid = (st + end) / 2;

		int budget = 0;
		for (int i = 0; i < n; i++) {
			budget += (vec[i] > mid) ? mid : vec[i];
		}

		if (budget > m) end = mid;
		else st = mid;
	}
	cout << st;
}