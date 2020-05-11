#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int M, N, H;
int map[MAX][MAX][MAX];
int visted[MAX][MAX][MAX];
queue<pair<pair<int, int>,int>> q;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int check() {
	int maxnum = 0;
	for (int h = 0; h < H; ++h) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j][h] == 0) return -1;
				else if (visted[i][j][h] > maxnum)
					maxnum = visted[i][j][h];
			}
		}
	}
	return maxnum-1;
}
void BFS() {
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int ch = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nh = ch + dh[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && nh >=0 && nh < H) {
				if (visted[nx][ny][nh] == 0 && map[nx][ny][nh] == 0) {
					visted[nx][ny][nh] = visted[cx][cy][ch] + 1;
					q.push({make_pair(nx, ny),nh});
					map[nx][ny][nh] = 1;
				}
				else if (map[nx][ny][nh] == -1 && visted[nx][ny][nh] == 0) {
					visted[nx][ny][nh] = -1;
				}
			}
		}
	}
	cout << check() << endl;
}

int main() {
	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j][h];
				if (map[i][j][h] == 1 && visted[i][j][h] == 0) {
					q.push({ { i, j },h });
					visted[i][j][h] = 1;
				}
			}
		}
	}
	BFS();
	return 0;
}