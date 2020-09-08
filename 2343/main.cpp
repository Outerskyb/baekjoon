#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec;
	int max = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
		if (temp > max) max = temp;
	}

	int st = max, end = 1000000002;
	while (st+1  < end) {	
		int mid = (st + end) / 2;
		int cnt = 0;
		int length = 0;
		for (int i = 0; i < N; i++) {
			if (length + vec[i] >= mid ) {
				length = vec[i];
				cnt++;
			}
			else {
				length += vec[i];
			}
		}
		if (length != 0) cnt++;
		if (cnt > M) st = mid;
		else end = mid;
	}
	cout << st;
}