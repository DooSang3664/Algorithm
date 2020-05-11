#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
#define INF 987654321
#define MAX 125+1

int N;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int out;
void BFS(int x, int y) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
	q.push({ map[x][y],{x,y} });
	dist[x][y] = map[x][y];
	while (!q.empty()) {
		int cx = q.top().second.first;
		int cy = q.top().second.second;
		int c_cost = q.top().first;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];		
			int n_cost = c_cost + map[nx][ny];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {			
				if ( dist[nx][ny] > n_cost) {
					dist[nx][ny] = n_cost;
					q.push({n_cost ,{ nx,ny } });
				}
			}
		}
	}
	out = dist[N - 1][N - 1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int cnt = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}
		memset(visit, false, sizeof(visit));
		BFS(0, 0);
		cout << "Problem "<< cnt <<": "<< out << endl;
		cnt++;
	}
	return 0;
}