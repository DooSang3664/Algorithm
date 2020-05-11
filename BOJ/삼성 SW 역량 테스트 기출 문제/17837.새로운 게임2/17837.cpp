#include <iostream>
#include <vector>
using namespace std;
#define MAX 13
struct chess
{
	int x;
	int y;
	int dir;
};
int N, K;
vector<int> map_s[MAX][MAX];
int map[MAX][MAX];
chess ch[11];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int dir_change(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;
}
void move(int x,int y,int nx,int ny, int ch_num,int cnt,int check) {
	if (check == 0) {		
		int a = 0;;
		for (int i = cnt; i < map_s[x][y].size(); ++i) {
			map_s[nx][ny].push_back(map_s[x][y][i]);
			ch[map_s[x][y][i]].x = nx;
			ch[map_s[x][y][i]].y = ny;
			a++;
		}
		for (int i = 0; i < a; ++i) {
			map_s[x][y].pop_back();
		}		
	}
	else if (check == 1) {
		int a = 0;;
		for (int i = map_s[x][y].size()-1; i >= cnt; --i) {
			map_s[nx][ny].push_back(map_s[x][y][i]);
			ch[map_s[x][y][i]].x = nx;
			ch[map_s[x][y][i]].y = ny;
			a++;
		}
		for (int i = 0; i < a; ++i) {
			map_s[x][y].pop_back();
		}
	}
	else if (check == 2) {
		int n_dir = dir_change(ch[ch_num].dir);
		ch[ch_num].dir = n_dir;
		nx = x + dx[n_dir];
		ny = y + dy[n_dir];
		if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
			if(map[nx][ny] != 2)
				move(x, y, nx, ny, ch_num, cnt, map[nx][ny]);
		}
	}
}

void go() {
	int time = 0;
	bool flag = false;
	while (1) {
		if (time > 1000) {
			break;
		}
		for (int i = 0; i < K; ++i) {
			int cx = ch[i].x;
			int cy = ch[i].y;
			int c_dir = ch[i].dir;

			int nx = cx + dx[c_dir];
			int ny = cy + dy[c_dir];
			
			//그 자리의 몇번째 체스
			int cnt;
			for (int j = 0; j < map_s[cx][cy].size(); ++j) {
				if (i == map_s[cx][cy][j]) {
					cnt = j;
					break;
				}
			}
			
			if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
				move(cx,cy,nx,ny,i,cnt,map[nx][ny]);
			}
			else {
				move(cx, cy, nx, ny, i, cnt,2);
			}
			//4개가 쌓였는지 체크
			for (int i = 0; i < K; ++i) {
				if (map_s[ch[i].x][ch[i].y].size() >= 4) {
					flag = true;
					break;
				}
			}

		}
		if (flag == true) {
			break;
		}
		time++;
	}
	if (flag == true) {
		cout << time+1 << endl;
	}
	else cout << -1 << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		int x, y, dir;
		cin >> x >> y >> dir;
		ch[i] = { x,y,dir };
		map_s[x][y].push_back(i);
	}
	go();
	return 0;
}
