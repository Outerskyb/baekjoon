#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, S;
	int ar[21];
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}
	int cnt = 0;
	int sum = 0;
	vector<int> vec(N);
	for (auto&el : vec)el = ++sum;
	sum = 0;
	for (float i = 0; i < pow(2, N); i++) {
		int t = i;
		for (int j = N-1; j >= 0; j--) {
			if (t / (1 << j) == 1) {
				sum += ar[j];
				t -= (1 << j);
			}
			
		}
		if (sum == S)  cnt++;  
		sum = 0;
	}
	
	std::cout << cnt;
}