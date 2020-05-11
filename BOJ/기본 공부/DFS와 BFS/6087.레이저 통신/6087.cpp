#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 101
#define endl '\n'

int W, H;
char map[MAX][MAX];
int check[MAX][MAX];
vector<pair<int, int>>C;

int dx[5] = {0,0,1,-1 };
int dy[5] = {1,-1,0,0 };

int BFS(int x, int y) {
	queue<pair<pair<int, int>, pair<int, int>>>q; // x,y,방향,거울수
	for (int i = 0; i < 4; ++i) {
		q.push({ {x,y},{i,0} });
	}
	check[x][y] = 0;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cs = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int ncnt = cnt;
			if (nx >= 0 && ny >= 0 && nx < H && ny < W) {
				if (map[nx][ny] != '*') {
					if (cs != i) ncnt++;
					if (check[nx][ny] >= ncnt) {
						check[nx][ny] = ncnt;
						q.push({ {nx,ny}, {i,ncnt} });
					}
				}
			}
		}
	}
	return check[C[1].first][C[1].second];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> W >> H;
	for (int i = 0; i < H; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < W; ++j) {
			if (temp[j] == 'C')
				C.push_back({ i,j });
			map[i][j] = temp[j];
			check[i][j] = 987654321;
		}
	}
	cout << BFS(C[0].first, C[0].second);
	return 0;
}