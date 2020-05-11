#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000+1
#define INF 987654321
#define endl '\n'
using namespace std;
int N, M;
vector<pair<int, int>> v[MAX];
int dist[MAX];

void funtion(int start) {
	priority_queue<pair<int, int>> q;
	q.push({ start,0 });
	dist[start] = 0;
	while (!q.empty()) {
		int cx = q.top().first;
		//int cx_cost = -q.top().second;
		q.pop();
		for (int i = 0; i < v[cx].size(); ++i) {
			int nx = v[cx][i].first;
			int nx_cost = v[cx][i].second;
			if (dist[nx] > dist[cx] + nx_cost) {
				dist[nx] = dist[cx] + nx_cost;
				q.push({ nx,-nx_cost });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int start, end;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		v[from].push_back({ to,m });
	}
	for (int i = 1; i <= N; ++i) {
		dist[i] = INF;
	}
	cin >> start >> end;
	funtion(start);
	cout << dist[end] << endl;
	return 0;
}