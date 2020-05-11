#include <iostream>
#include <queue>
using namespace std;
#define MAX 100+1

int N, M;
int map[MAX][MAX];
bool check[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int x, int y) {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { x,y },1 });
	check[x][y] = true;
	while (!q.empty()) {	
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cc = q.front().second;
		q.pop();
		if (cx == N - 1 && cy == M - 1) {
			cout << cc << endl;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (check[nx][ny] == false && map[nx][ny] == 1) {
					q.push({ { nx,ny },cc + 1 });
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; ++j) {
			map[i][j] = temp[j] - '0';
		}
	}
	BFS(0, 0);
}