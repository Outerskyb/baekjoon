#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 0;
	while (1) {
		tc++;
		int n;
		cin >> n;
		vector<vector<int>> blocks(31);
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			blocks[i].push_back(x), blocks[i].push_back(y), blocks[i].push_back(z);
			sort(blocks[i].begin(), blocks[i].end());
		}
		int x = 987654321, y = 987654321;
		int h = 0;
		while (1) {
			int temp_x = 0, temp_y = 0, temp_h = 0;
			for (int i = 0; i < n; i++) {
				if (blocks[i][0] > temp_x && blocks[i][0] <x
					&& blocks[i][1]>temp_y && blocks[i][1] < y) {
					temp_x = blocks[i][0], temp_y = blocks[i][1], temp_h = blocks[i][2];
				}if (blocks[i][0] > temp_x && blocks[i][0] <x
					&& blocks[i][2]>temp_y && blocks[i][2] < y) {
					temp_x = blocks[i][0], temp_y = blocks[i][2], temp_h = blocks[i][1];
				}if (blocks[i][1] > temp_x && blocks[i][1] <x
					&& blocks[i][2]>temp_y && blocks[i][2] < y) {
					temp_x = blocks[i][1], temp_y = blocks[i][2], temp_h = blocks[i][0];
				}
			}
			if (temp_x < x && temp_y < y) {
				x = temp_x, y = temp_y, h += temp_h;
			}
			else {
				break;
			}
		}
		cout <<"Case "<<tc<<": maximum height = "<< h << '\n';
	}
}