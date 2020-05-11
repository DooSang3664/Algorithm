#include<iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100
#define INF 987654321
struct point {
	int x;
	int y;
};
int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void BFS() {
	queue<point> q;
	q.push({ 0,0});
	visited[0][0] = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visited[nx][ny] > visited[cx][cy] + map[nx][ny]) {
					visited[nx][ny] = visited[cx][cy] + map[nx][ny];
					q.push({ nx,ny });
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
		
		cin >> N;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < MAX; ++i) {
			for (int j = 0; j < MAX; ++j) {
				visited[i][j] = INF;
			}
		}
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < N; ++j) {
				map[i][j] = s[j] - '0';
			}
		}
		BFS();
		cout << "#" << test_case << " " << visited[N - 1][N - 1] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}