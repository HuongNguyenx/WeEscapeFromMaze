#include <iostream>
using namespace std;

int m, n;
int maze[100][100], visited[100][100];
pair<int, int> previous[100][100];

void print(int x, int y) {
	maze[x][y] = 2;
	while (x != 0 && y != 0) {
		int t = previous[x][y].first;
		int k = previous[x][y].second;
		maze[t][k] = 2;
		x = t;
		y = k;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void findWay(int x, int y, int parent_x, int parent_y) {
	if (visited[x][y] == 0 && maze[x][y] == 0 && x > 0 && x <= m && y > 0 && y <= n) {
		visited[x][y] = 1;
		previous[x][y].first = parent_x;
		previous[x][y].second = parent_y;
		if (x == m && y == n) {
			print(x, y);
		}
		findWay(x, y - 1, x, y);
		findWay(x, y + 1, x, y);
		findWay(x + 1, y, x, y);
		findWay(x - 1, y, x, y);
	}
	else visited[x][y] = 1;
}

int main() {
	cin >> m >> n;
	previous[0][0].first = 0;
	previous[0][0].second = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			visited[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maze[i][j];
		}
	}
	findWay(1, 1, 0, 0);
	return 0;
}






