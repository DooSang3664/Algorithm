#include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
struct hool {
	int x;
	int y;
	int num;
};
struct point {
	int x;
	int y;
	int dir;
};
int N;
int map[MAX][MAX];
vector<hool> v;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int out = 0;
int ch_dir(int dir,int x,int y) {
	if (dir == 0) {
		if (map[x][y] == 1) return 2;
		else if (map[x][y] == 2) return 1;
		else if (map[x][y] == 3) return 3;
		else if (map[x][y] == 4) return 2;
		else if (map[x][y] == 5) return 2;		
	}
	else if (dir == 1) {
		if (map[x][y] == 1) return 3;
		else if (map[x][y] == 2) return 3;
		else if (map[x][y] == 3) return 2;
		else if (map[x][y] == 4) return 0;
		else if (map[x][y] == 5) return 3;
	}
	else if (dir == 2) {
		if (map[x][y] == 1) return 1;
		else if (map[x][y] == 2) return 0;
		else if (map[x][y] == 3) return 0;
		else if (map[x][y] == 4) return 3;
		else if (map[x][y] == 5) return 0;
	}
	else if (dir == 3) {
		if (map[x][y] == 1) return 0;
		else if (map[x][y] == 2) return 2;
		else if (map[x][y] == 3) return 1;
		else if (map[x][y] == 4) return 1;
		else if (map[x][y] == 5) return 1;
	}
}
int dir_limt(int dir) {
	if (dir == 0) return 2;
	else if (dir == 1) return 3;
	else if (dir == 2) return 0;
	else if (dir == 3) return 1;
}
void BFS(int x,int y,int dir) {
	queue<point>q;
	q.push({ x,y,dir });
	int num = 0;
	bool start = false;
	while (!q.empty()) {		
		int cx = q.front().x;
		int cy = q.front().y;
		int c_dir = q.front().dir;
		q.pop();

		if ((cx == x && cy == y) || (map[cx][cy] == -1)) {
			if (start) {
				if (out < num) {
					out = num;
				}
				break;
			}
			else {
				start = true;
			}
		}
		int nx = cx + dx[c_dir];
		int ny = cy + dy[c_dir];
		int n_dir;
		//벽에 부딪힐 경우
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			num++;
			q.push({ nx,ny,dir_limt(c_dir) });
		}
		//아무것도 아닌곳
		else if (map[nx][ny] == 0 || map[nx][ny] == -1) {
			n_dir = c_dir;
			q.push({ nx,ny,n_dir });
		}
		// 벽돌에 부딪힐 경우
		else if (map[nx][ny] < 6) {
			num++;
			n_dir = ch_dir(c_dir,nx,ny);
			q.push({ nx,ny,n_dir });
		}
		// 웜홀에 닿을경우
		else if (map[nx][ny] >= 6) {
			for (int i = 0; i < v.size(); ++i) {
				if (map[nx][ny] == v[i].num) {
					if (v[i].x != nx || v[i].y != ny) {
						q.push({ v[i].x,v[i].y,c_dir });
					}
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		out = 0;
		cin >> N;
		v.clear();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				if (map[i][j] > 5) {
					v.push_back({ i,j,map[i][j] });
				}
			}
		}
		//BFS(6, 0, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] == 0) {
					for (int d = 0; d < 4; ++d) {
						BFS(i, j, d);
					}
				}
			}
		}
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}