#include <iostream>
#include <cstring>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int dp[2000][2000];

vector<int> A;
vector<int> B;

int f(int a, int b) {
	if (a < 0 || b < 0) return  0;
	int& r = dp[a][b];
	if (r != -1) return r;

	if (A[a] > B[b]) {
		r = max(max(f(a-1,b),f(a-1,b-1)),(f(a, b - 1) + B[b]));
	}
	else {
		r = max(f(a-1, b), f(a - 1, b - 1));
	}
	return r;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	A = vector<int>(N);
	B = vector<int>(N);
	for (int i = N - 1; i >= 0; i--) { cin >> A[i]; }
	for (int i = N - 1; i >= 0; i--) { cin >> B[i]; }
	memset(dp, -1, 2000 * 2000 * 4);

	cout << f(N - 1, N - 1);


}