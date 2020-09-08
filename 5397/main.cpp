#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		list<char> li;
		auto it = li.begin();
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i])
			{
			case '<':
				if (it != li.begin())
					--it;
				break;
			case '>':
				if (it != li.end())
					++it;
				break;
			case '-':
				if (it != li.begin()) {
					auto it2 = --it;
					if (it != li.begin()) {
						--it;
						li.erase(it2);
						++it;
					}
					else {
						li.erase(it2);
						it = li.begin();
					}
				}
				if (li.size() == 0) it = li.begin();
				break;
			default:
				li.insert(it, s[i]);
				break;
			}
		}
		for (auto el : li)
			cout << el;
		cout << '\n';
	}
}