#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int map[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 10;
	}

	int h = 0;
	deque<pair<int, int>> snake;
	snake.push_back({ 0,0 });
	int L;
	cin >> L;
	int now = 0;
	for (int i = 0; i < L; i++) {
		int t; char w;
		cin >> t >> w;
		int len = t - now;
		if (h == 0) {
			for (int j = 0; j < len; j++) {
				if (snake[snake.size() - 1].second >= N
					|| find(snake.begin(), snake.end(), make_pair(snake[snake.size() - 1].first, snake[snake.size() - 1].second + 1)) != snake.end())
				{
					cout << now; return 0;
				}
				snake.push_back({ snake[snake.size() - 1].first, snake[snake.size() - 1].second + 1 });
				if (map[snake[snake.size() - 1].first][snake[snake.size() - 1].second + 1] != 10)
					snake.pop_front();
				now++;
			}
		}
		else if (h == 1) {
			for (int j = 0; j < len; j++) {
				if (snake[snake.size() - 1].first >= N
					|| find(snake.begin(), snake.end(), make_pair(snake[snake.size() - 1].first + 1, snake[snake.size() - 1].second)) != snake.end()) {
					cout << now; return 0;
				}
				snake.push_back({ snake[snake.size() - 1].first + 1, snake[snake.size() - 1].second });
				if (map[snake[snake.size() - 1].first + 1][snake[snake.size() - 1].second] != 10)
					snake.pop_front();
				now++;
			}
		}
		else if (h == 2) {
			for (int j = 0; j < len; j++) {
				if (snake[snake.size() - 1].second < 0
					|| find(snake.begin(), snake.end(), make_pair(snake[snake.size() - 1].first, snake[snake.size() - 1].second - 1)) != snake.end()) { cout << now; return 0; }
				snake.push_back({ snake[snake.size() - 1].first, snake[snake.size() - 1].second - 1 });
				if (map[snake[snake.size() - 1].first][snake[snake.size() - 1].second - 1] != 10)
					snake.pop_front();
				now++;
			}
		}
		else if (h == 3) {
			for (int j = 0; j < len; j++) {
				if (snake[snake.size() - 1].first < 0
					|| find(snake.begin(), snake.end(), make_pair(snake[snake.size() - 1].first - 1, snake[snake.size() - 1].second)) != snake.end()) { cout << now; return 0; }
				snake.push_back({ snake[snake.size() - 1].first - 1, snake[snake.size() - 1].second });
				if (map[snake[snake.size() - 1].first - 1][snake[snake.size() - 1].second] != 10)
					snake.pop_front();
				now++;
			}
		}
		h += (w == 'L') ? 3 : 1;
		h %= 4;
	}
	int len = N + 1;
	if (h == 0) {
		for (int j = 0; j < len; j++) {
			if (snake[snake.size() - 1].second >= N) { cout << now; return 0; }
			snake.push_back({ snake[snake.size() - 1].first, snake[snake.size() - 1].second + 1 });
			if (map[snake[snake.size() - 1].first][snake[snake.size() - 1].second + 1] != 10)
				snake.pop_front();
			now++;
		}
	}
	else if (h == 1) {
		for (int j = 0; j < len; j++) {
			if (snake[snake.size() - 1].first >= N) { cout << now; return 0; }
			snake.push_back({ snake[snake.size() - 1].first + 1, snake[snake.size() - 1].second });
			if (map[snake[snake.size() - 1].first + 1][snake[snake.size() - 1].second] != 10)
				snake.pop_front();
			now++;
		}
	}
	else if (h == 2) {
		for (int j = 0; j < len; j++) {
			if (snake[snake.size() - 1].second < 0) { cout << now; return 0; }
			snake.push_back({ snake[snake.size() - 1].first, snake[snake.size() - 1].second - 1 });
			if (map[snake[snake.size() - 1].first][snake[snake.size() - 1].second - 1] != 10)
				snake.pop_front();
			now++;
		}
	}
	else if (h == 3) {
		for (int j = 0; j < len; j++) {
			if (snake[snake.size() - 1].first < 0) { cout << now; return 0; }
			snake.push_back({ snake[snake.size() - 1].first - 1, snake[snake.size() - 1].second });
			if (map[snake[snake.size() - 1].first - 1][snake[snake.size() - 1].second] != 10)
				snake.pop_front();
			now++;
		}
	}
}