#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

bool paper[501][501];
vector<int> sizes;
int n, m;

queue<pair<int, int>> q;
bool visited[501][501]{ false };

int bfs(int i, int j) {
	q.push({ i, j });
	visited[i][j] = true;
	int size{ 1 };

	while (!q.empty()) {
		int cur_x{ q.front().x };
		int cur_y{ q.front().y };
		q.pop();

		int dx[4]{ 0, 1, 0, -1 };
		int dy[4]{ 1, 0, -1, 0 };

		for (int i{ 0 }; i < 4;i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) continue;
			if (visited[next_x][next_y]) continue;

			if (paper[next_x][next_y]) {
				q.push({ next_x, next_y });
				visited[next_x][next_y] = true;
				size++;
			}
		}
		
	}
	return size;
}

int main() {
	cin >> n >> m;

	for (int i{ 1 }; i <= n; i++) {
		for (int j{ 1 }; j <= m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int i{ 1 }; i <= n; i++) {
		for (int j{ 1 }; j <= m; j++) {
			if (visited[i][j] || !paper[i][j]) continue;
			sizes.push_back(bfs(i, j));
		}
	}

	sort(sizes.begin(), sizes.end());
	cout << sizes.size() << "\n" << ((sizes.empty()) ? 0 : sizes.back()) << "\n";
}