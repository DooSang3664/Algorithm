#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100+1
#define INF 987654321
#define endl '\n'

using namespace std;

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> m;
	//초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) map[i][j] = INF;
		}
	}
	//셋팅
	for (int i = 0; i < m; ++i) {
		int from, to, time;
		cin >> from >> to >> time;
		if (!map[from][to]) {
			map[from][to] = time;
		}
		else {
			map[from][to] = min(map[from][to], time);
		}
	}
	//플로이드
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	//출력
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			if (map[k][i] == INF) map[k][i] = 0;
			cout << map[k][i] << " ";
		}
		cout << endl;
	}
	return 0;
}