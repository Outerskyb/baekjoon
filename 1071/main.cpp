#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count[1001] = { 0 };
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		++count[temp];
	}
	for (int i = 0; i <= 1000; i++) {
		if (count[i] > 0 && count[i+1] == 0) {
			for (int j = 0; j < count[i]; j++) {
				cout << i << ' ';
			}
		}
		else if (count[i] > 0 && count[i+1]>0) {
			int key = i;
			for (int j = i+2; j <= 1000; j++) {
				if (count[j]) {	key = j;	break;}
			}
			if (key == i) {
				for (int j = 0; j < count[i + 1]; j++) {
					cout << i + 1 << ' ';
				}
				count[i + 1] = 0;
				for (int j = 0; j < count[i]; j++) {
					cout << i << ' ';
				}
			}
			else {
				--count[key];
				for (int j = 0; j < count[i]; j++) {
					cout << i << ' ';
				}
				cout << key << ' ';
				
			}
		}
	}
}