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
	while (e - s > r - l + 1)
	{
		int left_h = (l > s) ? min(h, H[l - 1]) : -1;
		int right_h = (r < e-1) ? min(h, H[r + 1]) : -1;
		if (left_h > right_h) {
			h = left_h;
			l--;
		}
		else {
			h = right_h;
			r++;
		}
		w++;
		ret = max(ret, w * h);
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	H = vector<int>(N);
	for (int i = 0; i < N; i++) scanf("%d", &H[i]);
	cout << rectangle(0, N);
}