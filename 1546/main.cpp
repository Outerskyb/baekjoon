#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	float n, sum = 0;
	cin >> n;
	vector<float> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	auto M = *(max_element(vec.begin(), vec.end()));
	for (auto& el : vec) sum+=el * (100.0 / M);
	printf("%f",sum / n);
}