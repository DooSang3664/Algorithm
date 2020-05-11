#include <iostream>
#include <vector>
using namespace std;

#define MAX 9
int map[MAX][MAX];
vector<pair<int, int>> point;
int pointnum;

bool chack(int num, int x, int y) {
	int rx = x / 3 * 3, ry = y / 3 * 3;
	for (int i = 0; i < 9; i++)
		if (map[x][i] == num || map[i][y] == num) return false;
	for (int i = rx; i < rx + 3; i++)
		for (int j = ry; j < ry + 3; j++)
			if (map[i][j] == num) return false;
	return true;
}

void DFS(int cnt) {
	if (cnt == pointnum) {
		for (int i = 0; i < MAX; ++i) {
			for (int j = 0; j < MAX; ++j) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	for (int i = 1; i <= MAX; ++i) {
		int x = point[cnt].first;
		int y = point[cnt].second;
		if (chack(i, x, y)) {
			map[x][y] = i;
			DFS(cnt + 1);
			map[x][y] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				point.push_back({ i,j });
		}
	}
	pointnum = point.size();
	DFS(0);
	return 0;
}