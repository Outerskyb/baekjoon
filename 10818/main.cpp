#include <set>
#include <iostream>

using namespace std;

int main() {
	int N;
	set<int> st;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		st.insert(temp);
	}

	cout << *(st.begin()) <<' '<< *(--st.end());
}