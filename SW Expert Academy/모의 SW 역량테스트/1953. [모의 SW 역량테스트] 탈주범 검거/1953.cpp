#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
#define MAX 50

int map[MAX][MAX];
bool visited[MAX][MAX];
int N, M, R, C, L;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool check(int x, int y, int nx, int ny) {
	if (nx - x == -1) {
		if (map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 7) {
			return false;
		}
	}
	if (nx - x == 1) {
		if (map[nx][ny] == 3 || map[nx][ny] == 5 || map[nx][ny] == 6) {
			return false;
		}
	}
	if (ny - y == 1) {
		if (map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 5) {
			return false;
		}
	}
	if (ny - y == -1) {
		if (map[nx][ny] == 2 || map[nx][ny] == 6 || map[nx][ny] == 7) {
			return false;
		}
	}
	return true;
}

int BFS(int x,int y) {
	int num = 0;
	queue<pair<int,pair<int, int>>>q;
	visited[x][y] = true;
	q.push({ 1,{ x, y } });
	while (!q.empty()) {
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int ct = q.front().first;
		q.pop();
		if (ct > L) {
			return num;
		}
		num++;
		if (map[cx][cy] == 1) {
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];				
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 2) {
			for (int i = 0; i < 2; ++i) {
				int nx = cx + dx[i];
				int ny = cy;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 3) {
			for (int i = 2; i < 4; ++i) {
				int nx = cx;
				int ny = cy+ dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 4) {
			for (int i = 0; i < 2; ++i) {
				int nx = cx, ny= cy;
				if (i == 0)	nx--;
				else ny++;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 5) {
			for (int i = 0; i < 2; ++i) {
				int nx = cx, ny = cy;
				if (i == 0)	nx++;
				else ny++;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 6) {
			for (int i = 0; i < 2; ++i) {
				int nx = cx, ny = cy;
				if (i == 0)	nx++;
				else ny--;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
		else if (map[cx][cy] == 7) {
			for (int i = 0; i < 2; ++i) {
				int nx = cx, ny = cy;
				if (i == 0)	nx--;
				else ny--;
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					if (check(cx, cy, nx, ny)) {
						q.push({ ct + 1,{ nx, ny } });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
	return num;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, 0, sizeof(visited));
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j];
			}
		}
		cout << "#" << test_case << " " << BFS(R, C) << endl;;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}