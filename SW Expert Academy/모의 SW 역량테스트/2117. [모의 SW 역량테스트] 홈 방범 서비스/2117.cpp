#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 20
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>> hoom;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int out = 0;
void bfs(int x,int y) {
	//거리까지 닿는 집들 계산
	queue<pair<pair<int, int>, int>>q;
	visited[x][y] = true;
	int dist = 1;
	int homecnt = 0;
	if (map[x][y] == 1) {
		homecnt = 1;
	}
	q.push({ {x,y},1 });
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int c_dist = q.front().second;
		q.pop();
		if (dist != c_dist) {
			int hv = homecnt * M;
			int bv = c_dist * c_dist + (c_dist - 1) * (c_dist - 1);
			if (hv >= bv) {
				if(out < homecnt)
					out = homecnt;
			}
			dist = c_dist;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] == false) {
					q.push({ {nx,ny},c_dist + 1 });
					visited[nx][ny] = true;
					if (map[nx][ny] == 1) {
						homecnt++;
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
		out = 1;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					hoom.push_back({ i,j });
				}
			}
		}
		//모든칸
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				memset(visited,0,sizeof(visited));
				bfs(i, j);
			}
		}
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}