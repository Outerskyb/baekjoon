#include <iostream>

using namespace std;

int heap[200002];
int leap = 1;

void update(int n) {
	heap[leap] = n;
	int curr = leap;
	while (curr != 1 && heap[curr / 2] < heap[curr]) {
		int temp = heap[curr / 2];
		heap[curr / 2] = heap[curr];
		heap[curr] = temp;
		curr /= 2;
	}
	leap++;
}
void top() {
	if (leap == 1) {
		cout << 0<<'\n'; return;
	}
	cout << heap[1]<<'\n';
	heap[1] = heap[--leap];
	heap[leap] = 0;
	int curr = 1;
	while (curr <= leap && (heap[curr * 2] > heap[curr] || heap[curr * 2 + 1] > heap[curr])) {
		if (heap[curr * 2] > heap[curr*2+1]) {
			int temp = heap[curr * 2];
			heap[curr * 2] = heap[curr];
			heap[curr] = temp;
			curr = curr * 2;
		}
		else {
			int temp = heap[curr * 2 + 1];
			heap[curr * 2 + 1] = heap[curr];
			heap[curr] = temp;
			curr = curr * 2+1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) top();
		else update(temp);
	}
}
/*
46
1
1
2
1
1
3
1
1
5
2
4
3
1
4
1
8
98
4
1
3
5
14
2
3
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0


*/