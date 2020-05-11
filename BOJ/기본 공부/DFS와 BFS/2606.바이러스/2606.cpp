#include <iostream>
#include <queue>
using namespace std;

#define MAX 100+1
int N,M;
int map[MAX][MAX] = { 0, };
bool check[MAX];

void BFS(int cnt) {
	int count = 0;
	queue<int>q;
	q.push(cnt);
	check[cnt] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (check[i] == false && map[x][i] == 1) {
				q.push(i);
				count++;
				check[i] = true;
			}
		}
	}
	cout << count << endl;
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	BFS(1);
	return 0;
}