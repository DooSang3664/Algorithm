#include <iostream>
#include <queue>
using namespace std;
#define MAX 51
#define INF 987654321
struct point {
	int x;
	int y;
	int life;
};
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
vector<point> V;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = INF;
int ocnt = 0;
int min(int x, int y) { return x > y ? y : x; }

void ch() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visited[i][j] = INF;
		}
	}
}
int BFS() {
	queue<point> q;
	int time = 0;;
	int v_cnt = 0;
	for (int i = 0; i < V.size(); ++i) {
		if (V[i].life == true) {
			q.push({ V[i].x,V[i].y,0 });
			visited[V[i].x][V[i].y] = 0;
		}
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int c_time = q.front().life;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				//이미 간곳은 가까운 곳에서 먼저 갔다
				if (visited[nx][ny] == INF && map[nx][ny] != 1){
					visited[nx][ny] = c_time+1;
					if (map[nx][ny] == 0) {
						v_cnt++;
						time = visited[nx][ny]; // 마지막까지 가는곳이 가장 먼위치
					}
					q.push({ nx,ny,c_time+1 });
				}
			}
		}
	}
	if (ocnt == v_cnt) {
		return time;
	}
	else return INF;
}
void DFS(int cnt,int pos) {
	if (cnt == M) {
		ch();
		result = min(result, BFS());
		return;
	}
	for (int i = pos; i < V.size(); ++i) {
		if (V[i].life == false) {
			V[i].life = true;
			DFS(cnt + 1,i+1);
			V[i].life = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				V.push_back({ i,j,false });
			else if (map[i][j] == 0)
				ocnt++;
		}
	}
	DFS(0,0);
	if (result == INF) {
		cout << -1 << endl;
	}
	else cout << result << endl;

}