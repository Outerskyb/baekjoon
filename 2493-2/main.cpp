#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> vec(N);
	for (int i = 0; i < N; i++) scanf("%d",&vec[i]);

	vector<pair<int, int>> dnr;

	dnr.push_back(make_pair(vec[N - 1], N - 1));
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < dnr.size(); j++) {
			if (vec[i] >= dnr[j].first) vec[dnr[j].second] = i + 1, dnr.erase(dnr.begin() + j--);
		}
		/*for (auto it = dnr.begin(); dnr.size()!=0&&it != dnr.end(); ) {
			if (vec[i] >= (*it).first) vec[(*it).second] = i+1, dnr.erase(it++);
			else ++it;
		}*/
		dnr.push_back(make_pair(vec[i], i));
	}

	for (auto& p : dnr) vec[p.second] = 0;

	for (auto& el : vec) printf("%d ",el);

}