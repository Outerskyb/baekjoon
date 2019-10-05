#include <iostream>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

vector<int> H;

int rectangle(int s, int e)
{
	if (s == e) return 0;
	if (s + 1 == e) return H[s];
	int mid = (s + e) / 2;
	int ret = max(rectangle(s, mid), rectangle(mid, e));

	int w = 1, h = H[mid], l = mid, r = mid;
	while (e-s>r-l+1) {
		int p = l > s ? min(h, H[l - 1]) : -1; // 왼쪽으로 확장했을 경우의 높이
		int q = r < e - 1 ? min(h, H[r + 1]) : -1; // 오른쪽으로 확장했을 경우의 높이
		// 더 높은(같은) 높이를 가진 쪽으로 확장
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		// 최댓값 갱신
		++w;
		ret = max(ret, w * h);
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	H = vector<int>(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
	cout << rectangle(0, N);

}