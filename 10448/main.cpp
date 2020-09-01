#include <iostream>
#include <vector>

using namespace std;

vector<int> ur;
void u() {
	ur.push_back(1);
	for (int i = 1; ur[i - 1] < 1000; i++) {
		ur.push_back(i * (i + 1) / 2);
	}
}

int main()
{
	u();
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < ur.size(); i++) {
			for (int j = 0; j < ur.size(); j++) {
				for (int k = 0; k < ur.size(); k++) {
					if (ur[i] + ur[j] + ur[k] == N) {
						cout << 1 << '\n';
						goto jim;
					}
				}
			}
		}
		cout << 0 << '\n';
	jim:
		;
	}

}