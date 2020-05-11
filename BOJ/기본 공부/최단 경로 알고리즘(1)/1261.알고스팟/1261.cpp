#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100+1
#define endl '\n'
#define INF 987654321

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void funtion(int x,int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == 1) {
					if (dist[nx][ny] > dist[cx][cy]+1) {
						dist[nx][ny] = dist[cx][cy] + 1;
						q.push({ nx,ny });
					}
				}
				else if (map[nx][ny] == 0) {
					if (dist[nx][ny] > dist[cx][cy]) {
						dist[nx][ny] = dist[cx][cy];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; ++j) {
			map[i][j] = temp[j] - '0';
			dist[i][j] = INF;
		}
	}

	funtion(0, 0);

	cout << dist[N - 1][M - 1] << endl;
	return 0;
}