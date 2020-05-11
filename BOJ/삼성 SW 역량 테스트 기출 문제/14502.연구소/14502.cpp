#include <iostream>
#include <queue>
using namespace std;
#define MAX 9
struct point {
	int x;
	int y;
};
int N, M;
int map[MAX][MAX];
int copy_map[MAX][MAX];
vector<point> V;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = 0;
int ocnt = 0;
int max(int x, int y) { return x > y ? x : y; }
void map_copy() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			copy_map[i][j] = map[i][j];
		}
	}
}
int BFS() {
	queue<point> q;
	for (int i = 0; i < V.size(); ++i) {
		q.push(V[i]);
	}	
	int sum = 0;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;	
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (copy_map[nx][ny] == 0) {
					q.push({ nx,ny });
					copy_map[nx][ny] = 2;
					sum++;
				}
			}
		}
	}
	return ocnt - sum - 3;
}
void DFS(int cnt) {
	if (cnt == 3) {
		map_copy();
		result = max(result,BFS());
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) 
				V.push_back({ i,j });
			if (map[i][j] == 0)
				ocnt++;
		}
	}
	DFS(0);
	cout << result << endl;
}