#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

vector<pair<int, pair<int, int>>>v;
vector<int> sum;
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

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		dist[y] = x;
	}
}

bool checkUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		v.push_back({ m,{from,to} });
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= N; ++i) {
		dist[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (checkUnion(from, to) == false) {
			Union(from, to);
			sum.push_back(v[i].first);
		}
	}
	for (int i = 0; i < sum.size() - 1; ++i) {
		cnt += sum[i];
	}
	cout << cnt << endl;
	return 0;
}