#include <iostream>
#include <vector>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)>(b))?(a):(b))

using namespace std;

int N;
vector<int> A;

int dnq(int s, int e) 
{
	if (s == e) return 0;
	if (s + 1 == e) return A[s] * A[s];
	int mid = (s + e) / 2;
	int ret = max(dnq(0,mid),dnq(mid,e));

	int l = mid, r = mid, mini = A[mid],sum = 0;
	while (e - s > l - r + 1) 
	{
		if ( mini > A[l]) {
			if (r<e-1&&A[l] > A[r]) { // m l r
				sum += A[l];
				mini = A[l];
				l--;
			}
			else if(r < e - 1 && A[r]<mini){ // m r l
				sum += A[r];
				mini = A[r];
				r++;
			}
			else {				// r m l
				sum += A[r]; 
				r++;
			}
		}
		else {
			if (A[r] > A[l]) { //r l m
				sum += A[r];
				r++;
			}
			else if (A[r] < mini) { // l m r
				sum += A[l];
				l--;
			}
			else {				// l r m
				sum += A[l]; 
				l--;
			}
		}
		ret = max(ret, mini * sum);
	}
	return ret;
}

int main()
{
	cin >> N;
	A = vector<int>(N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	cout << dnq(0, N);

}