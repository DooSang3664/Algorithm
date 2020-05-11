#include<iostream>
#include <queue>

using namespace std;
#define MAX 21
int map[MAX][MAX]; //지도
bool visited[MAX][MAX]; // 간곳확인
int N;
bool num_chcek[101]; // 이미먹은 디저트 확인
int dx[5] = {1,1,-1,-1};
int dy[5] = {1,-1,-1,1};
int out = 0;
int startx, starty;
void DFS(int x,int y,int cnt,int dir) {
	if (cnt > 1 && x == startx && y == starty) {
		if (out < cnt) {
			out = cnt;
		}
		return;
	}
	for (int i = 0; i < 2; ++i) {
		int nx = x + dx[dir + i];
		int ny = y + dy[dir + i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[nx][ny] == false && num_chcek[map[nx][ny]] == false) {
				visited[nx][ny] = true;
				num_chcek[map[nx][ny]] = true;
				DFS(nx, ny, cnt + 1, dir + i);
				visited[nx][ny] = false;
				num_chcek[map[nx][ny]] = false;
		}
		else if (nx == startx && ny == starty) {
			DFS(nx, ny, cnt + 1, dir + i);
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
		out = -1;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				startx = i;
				starty = j;
				num_chcek[map[i][j]] = true;
				DFS(i, j,0,0);
				num_chcek[map[i][j]] = false;
			}
		}
		cout <<"#" << test_case << " "<< out << endl;
	}

	return 0;
}