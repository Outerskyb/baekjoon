#include <iostream>
#include <cmath>

using namespace std;

bool visit[10001];

int d(int n) {
	int s = n;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return  s;
}

int main()
{
	for (int i = 1; i <= 10000; i++) {
		if (visit[i]) continue;
		int curr = d(i);
		if (curr == i) continue;
		while (curr <= 10000) {
			if (visit[curr]) break;
			visit[curr] = true;
			curr = d(curr);
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (visit[i] == false) cout << i << '\n';
	}
}