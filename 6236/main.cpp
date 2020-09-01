#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N>>M;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	int st = 1; 
	int end = 1000000001;

	while (st + 1 < end) {
		int mid = (st + end) / 2;
		int money = 0,cnt = 0;
		for (int i = 0; i < N; i++) {
			if (money + vec[i] >= mid) {
				money = vec[i];
				cnt++;
			}
			else {
				money += vec[i];
			}
		}
		if (money != 0) cnt++;
		if (cnt > M) st = mid;
		else end = mid;

	}
	cout << st;
}