#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> p;
map<int, int> s;

void make_primes()
{
	p.push_back(2);
	s.insert({2,0});
	for (int i = 3; i <= 10000; i++) {
		bool isp = true;
		for (const auto& el : p) {
			if (i % el == 0) {
				isp = false; break;
			}
		}
		if (isp) {
			p.push_back(i);
			s.insert({ i, p.size()-1 });
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	make_primes();

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = (*s.upper_bound(n / 2)).second-1; i >= 0; i--) {
			if (s.find(n - p[i]) != s.end()) {
				cout << p[i] << ' ' << n - p[i] << '\n';
				break;
			}
		}
	}
}
