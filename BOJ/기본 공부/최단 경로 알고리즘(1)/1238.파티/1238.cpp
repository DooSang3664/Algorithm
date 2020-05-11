#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAX 10000+1
#define INF 987654321

int N, M, X;
vector<pair<int, int>> G[MAX];
int dist1[MAX];
int dist2[MAX];
vector<int> v; //최단거리의 집합

void Funtion(int start) {
	priority_queue<pair<int, int>> q;
	q.push({ start,0 });
	dist1[start] = 0;
	while (!q.empty()) {	
		int cx = q.top().first;
		int cx_cost = -q.top().second;
		q.pop();
		if (dist1[cx] < cx_cost) continue;
		for (int i = 0; i < G[cx].size(); ++i) {
			int nx = G[cx][i].first;
			int nx_cost = G[cx][i].second;
			if (dist1[nx] > dist1[cx] + nx_cost) {
				dist1[nx] = dist1[cx] + nx_cost;
				q.push({nx,-nx_cost});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;
	int out = 0;
	for (int i = 0; i < M; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		G[from].push_back({to,m});
	}

	for (int i = 1; i <= N; ++i) {
		for (int i = 1; i <= N; ++i) {
			dist1[i] = INF;
		}
		Funtion(i);
		dist2[i] = dist1[X];
	}
	for (int i = 1; i <= N; ++i) {
		dist1[i] = INF;
	}
	Funtion(X);
	for (int i = 1; i <= N; i++) {
		dist2[i] = dist2[i] + dist1[i];
	}
	sort(dist2 + 1, dist2 + N + 1);
	cout << dist2[N] << endl;
	return 0;
}