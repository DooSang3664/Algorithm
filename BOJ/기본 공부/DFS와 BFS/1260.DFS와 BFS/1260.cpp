#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
int map[1001][1001];
int check[1001];

void BFS(int idx) {
	queue<int> q;
	q.push(idx);
	check[idx] = true;
	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (check[i] == false && map[x][i] == 1) {
				q.push(i);
				check[i] = true;
			}
		}
	}
}
void DFS(int idx) {
	check[idx] = true;
	cout << idx << " ";
	for (int i = 1; i <= n; ++i) {
		if (check[i] == false && map[idx][i] == 1)
			DFS(i);
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	DFS(k);
	cout << endl;
	memset(check, false, sizeof(check));	
	BFS(k);
	return 0;
}