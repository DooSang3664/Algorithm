#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
int N, M, K;
int map[MAX][MAX];
int check[MAX][MAX];
vector<int> v;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int x,int y) {
	int count = 1;
	queue<pair<int, int>> q;
	q.push({x,y});
	check[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (check[nx][ny] == false && map[nx][ny] == 0) {
					q.push({nx,ny});
					check[nx][ny] = true;
					count++;
				}
			}
		}
	}
	v.push_back(count);
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; ++i) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int h = y; h < ny; ++h) {
			for (int j = x; j < nx; ++j) {
				map[h][j] = -1;
			}
		}
	}
	for (int j = 0; j < M; j++) {
		for (int h = 0; h < N; ++h) {
			if (check[j][h] == false && map[j][h] == 0)
				BFS(j, h);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}