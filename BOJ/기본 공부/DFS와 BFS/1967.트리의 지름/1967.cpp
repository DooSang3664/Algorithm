#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10001
#define endl '\n'

int n;
vector<pair<int, int>>v[MAX];
bool check[MAX];
int memo[MAX];

int BFS(int x) {
	memset(memo, 0, sizeof(memo));
	memset(check, false, sizeof(check));
	int max_sum = 0;
	queue<int> q;
	q.push(x);
	check[x] = true;
	memo[x] = 0;
	while (!q.empty()) {
		int cx = q.front();
		q.pop();
		for (int i = 0; i < v[cx].size(); ++i) {
			int nx = v[cx][i].first;
			int n_cost = v[cx][i].second;			
			if (check[nx] == false) {
				q.push(nx);
				check[nx] = true;
				memo[nx] += n_cost + memo[cx];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		max_sum = max(max_sum, memo[i]);
	}
	return max_sum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int out = 0;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int from, to, m;
		cin >> from >> to >> m;
		v[from].push_back({ to,m });
		v[to].push_back({ from,m });
	}
	for (int i = 1; i <= n; ++i) {
		out = max(out,BFS(i));
	}
	cout << out << endl;
	return 0;
}