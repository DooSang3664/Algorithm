#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 101
#define endl '\n'
int M, N;
int map[MAX][MAX];
int staet;
bool check[MAX][MAX][5];
int dx[5] = {0, 0,0, 1, -1 };
int dy[5] = {0, 1,-1,0,0 };
int lx, ly, ls;

bool go(int x, int y, int s, int num) {
	//갈수있나
	int nx = x + dx[s] * num;
	int ny = y + dy[s] * num;
	if (nx < 1 || ny < 1 || nx > M || ny > N) return false;
	//한칸씩도 갈수있나?
	nx = x;
	ny = y;
 	for (int i = 0; i < num; ++i) {
		nx += dx[s];
		ny += dy[s];
		if (map[nx][ny] == 1) return false;
	}
	return true;
}

int change_cs(int cs,char c) {
	if (c == 'L') {
		if (cs == 1) return 4;
		else if (cs == 2) return 3;
		else if (cs == 3) return 1;
		else if (cs == 4) return 2;
	}
	else if (c == 'R') {
		if (cs == 1) return 3;
		else if (cs == 2) return 4;
		else if (cs == 3) return 2;
		else if (cs == 4) return 1;
	}
}

int BFS(int sx,int sy,int ss) {
	queue<pair<pair<int, int>,pair<int,int>>> q;
	q.push({ {sx,sy},{ss,0} });
	check[sx][sy][ss] = true;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cs = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (cx == lx && cy == ly && cs == ls)
			return cnt;
		for (int i = 1; i <= 3; ++i) {
			if (go(cx, cy, cs, i) == true) {
				int nx = cx + dx[cs] * i;
				int ny = cy + dy[cs] * i;
				if (check[nx][ny][cs] == false) {
					q.push({ {nx,ny},{cs,cnt + 1} });
					check[nx][ny][cs] = true;
				}
			}
		}
		int ns;
		ns = change_cs(cs,'L');
		if (check[cx][cy][ns] == false) {
			check[cx][cy][ns] = true;
			q.push({ {cx,cy},{ns,cnt+1} });
		}
		ns = change_cs(cs, 'R');
		if (check[cx][cy][ns] == false) {
			check[cx][cy][ns] = true;
			q.push({ {cx,cy},{ns,cnt + 1} });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	int sx, sy, ss;
	cin >> sx >> sy >> ss;
	cin >> lx >> ly >> ls;
	cout << BFS(sx, sy,ss);

	return 0;
}