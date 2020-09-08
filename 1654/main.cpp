#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() 
{
	int K, N;
	cin >> K >> N;
	vector<uint64_t> vec;
	uint64_t st = 0;
	uint64_t end = 0;
	for (int i = 0; i < K; i++) {
		uint64_t temp;
		scanf("%llu", &temp);
		vec.push_back(temp);
		if (temp > end) end = temp;
	}
	end++;
	

	while (st + 1 < end) {
		uint64_t mid = (st + end) / 2;
		uint64_t cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += vec[i]/mid;
		}
		//cout<<st<< ' '<< mid<< ' ' << end<< ' ' << cnt<<'\n';
		if (cnt >= N) st = mid;
		else end = mid;
	}

	cout << st;

}
