#include <iostream>
#include <vector>
#include <algorithm>
#include <cinttypes>
using namespace std;

int main() 
{
	int N,M;
	cin >> N >> M;
	vector<uint64_t> vec;

	for (int i = 0; i < N; i++) {
		uint64_t temp;
		scanf("%llu", &temp);
		vec.push_back(temp);
	}


	int st = 0;
	int end = 1000000001;
	while (st +1< end) {
		int mid = (st + end) / 2;
		uint64_t sum = 0;
		for (int i = 0; i < N; i++) {
			if(vec[i]>mid) sum += vec[i] - mid;
		}
		if (sum >= M) st = mid;
		else end = mid;
	}
	printf("%d", st);
}