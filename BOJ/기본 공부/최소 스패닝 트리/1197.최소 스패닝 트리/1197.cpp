#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10001
int V, E;
vector<pair<int,pair<int, int>>> map;
int dist[MAX];

int Find(int x) {
	if (x == dist[x]) {
		return x;
	}
	else {
		int p = Find(dist[x]);
		dist[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		dist[y] = x;
	}
}

bool  checkUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool check = false;
	int output = 0;
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		map.push_back({ m,{from,to} });
	}
	sort(map.begin(), map.end());

	for (int i = 1; i <= V; ++i) {
		dist[i] = i;
	}

	for (int i = 0; i < E; ++i) {
		int from = map[i].second.first;
		int to = map[i].second.second;
		if (checkUnion(from, to) == false) {
			Union(from, to);
			output += map[i].first;
		}
	}
	cout << output << endl;
	return 0;
}
