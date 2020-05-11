#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100+1
#define INF 987654321

int N, M;
int map[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if(map[i][k] && map[k][j]) map[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (!map[i][j] && !map[j][i]) cnt++;
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}