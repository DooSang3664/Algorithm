#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int N,K,L;
int map[MAX][MAX];
bool check[MAX][MAX];
vector<pair<int, char>> cmd;

struct Snaek {
	int x;
	int y;
	int dir;
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int change_cs(int cs, char c) {
	if (c == 'L') {
		if (cs == 1) return 0;
		else if (cs == 2) return 1;
		else if (cs == 3) return 2;
		else if (cs == 0) return 3;
	}
	else if (c == 'D') {
		if (cs == 1) return 2;
		else if (cs == 2) return 3;
		else if (cs == 3) return 0;
		else if (cs == 0) return 1;
	}
}

int funtion() {
	deque<pair<int,int>>S;
	S.push_back( {0,0});
	int cx = 0;
	int cy = 0;
	int dir = 1;	
	int time = 0, cmd_cnt = 0;
	map[cx][cy] = 2;
	while (1) {
		time++;
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		if (map[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= N)) {
			return time;
		}
		else if (map[nx][ny] == 0) {
			map[nx][ny] = 2;
			map[S.back().first][S.back().second] = 0;
			S.pop_back();
			S.push_front({ nx,ny });
		}
		else if (map[nx][ny] == 1) {
			map[nx][ny] = 2;
			S.push_front({ nx,ny });
		}
		if (cmd_cnt < cmd.size()) {
			if (time == cmd[cmd_cnt].first) {
				dir = change_cs(dir, cmd[cmd_cnt].second);
				cmd_cnt++;
			}
		}
		cx = nx;
		cy = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) {
		int a; char d;
		cin >> a >> d;
		cmd.push_back({ a,d });
	}
	cout << funtion();
	return 0;
}