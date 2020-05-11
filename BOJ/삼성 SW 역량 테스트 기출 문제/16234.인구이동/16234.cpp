#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 51
int N, L, R;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool check = true;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int Diff(int cx, int cy, int nx, int ny) {
	return abs(map[cx][cy] - map[nx][ny]);
}

void BFS(int x,int y) {
	queue<pair<int, int>> q,sumQ;
	q.push({ x,y });
	sumQ.push({ x,y });
	visited[x][y] = true;
	int sum=0;
	int ans=0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;	
		q.pop();
		sum += map[cx][cy];
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] == false) {
					if (Diff(cx,cy,nx,ny) >= L && Diff(cx, cy, nx, ny) <= R) {
						q.push({ nx, ny });
						visited[nx][ny] = true;
						sumQ.push({ nx,ny });
						
					}
				}
			}
		}
	}
	ans = sum / sumQ.size();
	while (!sumQ.empty()) {
		map[sumQ.front().first][sumQ.front().second] = ans;
		sumQ.pop();
	}
}
int go_check(int x,int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (Diff(x, y, nx, ny) >= L && Diff(x, y, nx, ny) <= R) 
				return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	
	while (check) {
		check = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (visited[i][j] == false && go_check(i,j) == true ) {
					BFS(i, j);
					check = true;
				}
			}
		}
		if (check == true) cnt++;
		memset(visited, false, sizeof(visited));
	}
	cout << cnt << endl;
	return 0;
}