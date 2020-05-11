#include <iostream>
#include <queue>
using namespace std;

#define MAX 50

int N, M;
int map[MAX][MAX];
bool visitd[MAX][MAX];
int clar = 0;
struct Robot
{
	int x;
	int y;
	int dir;
};
Robot R;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ch_dir(int dir) {
	if (dir == 0) return 3;
	else if (dir == 3) return 2;
	else if (dir == 2) return 1;
	else if (dir == 1) return 0;
}
void BFS() {
	int cx = R.x;
	int cy = R.y;
	int c_dir = R.dir;
	map[cx][cy] = 2;
	clar++;
	int nx, ny, n_dir;
	
	while (1) {
		int count = 0;
		bool check = false;
		int Tmp_dir = c_dir;
		for (int i = 0; i < 4; ++i) {
			n_dir = ch_dir(c_dir);
			nx = cx + dx[n_dir];
			ny = cy + dy[n_dir];
			if (map[nx][ny] == 0) {
				check = true;
				break;
			}
			else if (map[nx][ny] == 1 || map[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M)) {
				c_dir = n_dir;
				count++;
			}
		}
		if (check) {
			map[nx][ny] = 2;
			clar++;
			c_dir = n_dir;
		}
		if (count == 4) {
			nx = cx - dx[Tmp_dir];
			ny = cy - dy[Tmp_dir];
			c_dir = Tmp_dir;
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || map[nx][ny] == 1) {
				break;
			}
		}
		cx = nx;
		cy = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> R.x >> R.y >> R.dir;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}
	BFS();
	cout << clar << endl;
	return 0;
}
