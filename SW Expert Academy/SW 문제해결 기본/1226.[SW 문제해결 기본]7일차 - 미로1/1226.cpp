#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct point
{
	int x;
	int y;
};
int map[16][16];
bool visited[16][16];
point start, Epoint;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool BFS() {
	queue<point> q;
	q.push({ start.x,start.y });
	visited[start.x][start.y] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		if (cx == Epoint.x && cy == Epoint.y) {
			return true;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16) {
				if (map[nx][ny] != 1 && visited[nx][ny] == false) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, false, sizeof(visited));
		int N;
		cin >> N;
		for (int i = 0; i < 16; ++i) {
			string temp;
			cin >> temp;
			for (int j = 0; j < 16; ++j) {
				if (temp[j] - '0' == 2) {
					start = { i,j };
				}
				else if (temp[j] - '0' == 3) {
					Epoint = { i,j };
				}
				map[i][j] = temp[j] - '0';
			}
		}
		if (BFS()) {
			cout << "#" << N << " " << 1 <<endl;
		}
		else {
			cout << "#" << N << " " << 0 << endl;
		}
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
