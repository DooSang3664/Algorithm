#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define MAX 300000+1
#define INF 987654321
using namespace std;
int V, E;
int start;
vector<pair<int, int>>v[MAX];
int dist[MAX]; // 최단거리 갱신 메모리
void Di(int start) {
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	dist[start] = 0;
	while (!q.empty()) {
		int cx_cost = -q.top().first;
		int cx = q.top().second;
		q.pop();
		for (int i = 0; i < v[cx].size(); ++i) {
			int nx_cost = v[cx][i].second;
			int nx = v[cx][i].first;
			if (dist[nx] > dist[cx] + nx_cost) {
				dist[nx] = dist[cx] + nx_cost;
				q.push({ -dist[nx],nx });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	cin >> start;
	//그래프 생성
	for (int i = 0; i < E; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		v[from].push_back({ to,m });
	}
	// 배열초기화
	for (int i = 1; i <= V; ++i) {
		dist[i] = INF;
	}
	Di(start);
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
	return 0;
}