#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;




int main()
{
	int n;
	int k;
	cin >> n >> k;

	set<string> st;
	vector<string> vec;

	for (int i = 0; i < n; i++) 
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				st.insert(vec[i] + vec[j]);
			}
		}
	}
	else if (k == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				for (int x = 0; x < n; x++) {
					if (x == i||x==j) continue;
					st.insert(vec[i] + vec[j]+vec[x]);
				}
			}
		}
	}
	else if (k == 4) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				for (int x = 0; x < n; x++) {
					if (x == i || x == j) continue;
					for (int y = 0; y < n; y++) {
						if (y == i || y == j||y==x) continue;
						st.insert(vec[i] + vec[j]+vec[x]+vec[y]);
					}
				}
			}
		}
	}

	cout << st.size();
}