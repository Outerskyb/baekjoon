#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> vec(N);
	vector<int> answer(N, 0);
	for (int i = 0; i < N; i++) scanf("%d", &vec[i]);

	set<pair<int, int>> dnr;

	dnr.insert(make_pair(vec[N - 1], N - 1));
	for (int i = N - 2; i >= 0; i--) {
		set<pair<int, int>>::iterator lb;
		for (auto it = dnr.begin(); it != (lb = dnr.lower_bound(make_pair(vec[i] - 1, N))); ) {
			auto tmp = ++it;
			--it;
			answer[(*it).second] = i + 1;
			dnr.erase(it);
			it = tmp;
		}
		/*for (auto it = dnr.begin(); dnr.size()!=0&&it != dnr.end(); ) {
			if (vec[i] >= (*it).first) vec[(*it).second] = i+1, dnr.erase(it++);
			else ++it;
		}*/
		dnr.insert(make_pair(vec[i], i));
	}
	for (auto& el : answer) printf("%d ", el);

}