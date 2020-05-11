#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 1000

int arr[MAX + 1][MAX + 1];
int visted[MAX + 1][MAX + 1];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N;
queue<pair<int, int>> q;

int check() {
	int maxnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) return -1;
			else if (visted[i][j] > maxnum)
				maxnum = visted[i][j];
		}
	}
	return maxnum - 1;
}
void BFS() {
	int cx, cy;
	while (!q.empty()) {
		cx = q.front().first;
		cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (visted[nx][ny] == 0 && arr[nx][ny] == 0) {
					visted[nx][ny] = visted[cx][cy] + 1;
					q.push(make_pair(nx, ny));
					arr[nx][ny] = 1;
				}
				else if (arr[nx][ny] == -1 && visted[nx][ny] == 0) {
					visted[nx][ny] = -1;
				}
			}
		}
	}
	cout << check() << endl;
}
int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1 && visted[i][j] == 0) {
				q.push(make_pair(i, j));
				visted[i][j] = 1;
			}
		}
	}
	BFS();
	return 0;
}

