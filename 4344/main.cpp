#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<int> vec;
		int sum = 0;
		for (int i = 0; i < N; i++) { int temp; scanf("%d", &temp); vec.push_back(temp); sum += temp; }
		sort(vec.begin(), vec.end());
		int st = 0;
		int end = N;
		while (st + 1 < end) {
			int mid = (st + end) / 2;
			if (vec[mid] > sum / N) end = mid;
			else st = mid;
		}
		printf("%.3f%%\n", (N-end)/ float(N)*100);
	}
}