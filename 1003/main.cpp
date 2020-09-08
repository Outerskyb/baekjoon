#include <iostream>
#include <vector>

using namespace std;

vector<int> f;

void mf() {
	f.push_back(0);
	f.push_back(1);
	int one = 0;
	int two = 1;
	int three ;
	for (int i = 0; i < 42; i++) {
		three = two + one;
		one = two;
		two = three;
		f.push_back(three);
	}
}
//

int main()
{
	int T;
	cin >> T;
	mf();
	while (T--) {
		int N;
		cin >> N;
		cout << ((N == 0) ? 1 : f[N-1]) <<' '<<f[N]<<'\n';
	}
}