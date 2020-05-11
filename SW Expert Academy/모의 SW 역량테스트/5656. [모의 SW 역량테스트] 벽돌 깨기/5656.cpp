#include<iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INF 500
int N, W, H;
int map[15][12];
int map_copy[15][12];
int startP[4];
int out = INF;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void boom(int start) {
	bool visited[15][12] = {0,};//초기화 꼭해줘야하더라
	queue<pair<int, int>>q;
	for (int i = 0; i < H; ++i) {
		if (map_copy[i][start] == 1) {
			map_copy[i][start] = 0;
			return;
		}
		else if (map_copy[i][start] > 1) {
			q.push({ i,start });
			visited[i][start] = true;
			break;
		}
	}
	//연쇄 폭발
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		int range = map_copy[cx][cy];
		map_copy[cx][cy] = 0;
		q.pop();
		for (int i = 1; i < range; i++) {
			for (int j = 0; j < 4; ++j) {
				int nx = cx + dx[j]*i;
				int ny = cy + dy[j] * i;
				if (nx >= 0 && ny >= 0 && nx < H && ny < W) {
					if (visited[nx][ny] == false && map_copy[nx][ny] != 0) {
						if (map_copy[nx][ny] == 1) {
							map_copy[nx][ny] = 0;
						}
						else if (map_copy[nx][ny] > 1) {
							q.push({ nx,ny });
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
	}
	//중력!
	for (int i = 0; i < W; ++i) {
		int x = H - 1;
		for (int j = H - 1; j >= 0; --j) {
			if (map_copy[j][i] != 0) {
				int temp = map_copy[j][i];
				map_copy[j][i] = 0;
				map_copy[x][i] = temp;
				x--;
			}
		}
	}
}
void DFS(int cnt) {
	if (cnt == N) {
		int boomcnt = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				map_copy[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; ++i) {
			boom(startP[i]);
		}

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (map_copy[i][j] > 0)
					boomcnt++;
			}
		}

		if (out > boomcnt)
			out = boomcnt;
		return;
	}
	for (int i = 0; i < W; ++i) {
		startP[cnt] = i;
		DFS(cnt + 1);
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(startP, 0, sizeof(startP));
		out = INF;
		cin >> N >> W >> H;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> map[i][j];
			}
		}
		DFS(0);
		cout << "#" << test_case << " "<<out << endl;
	}
	return 0;
}