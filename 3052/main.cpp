#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> st;
	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		st.insert(temp % 42);
	}
	cout << st.size();
}