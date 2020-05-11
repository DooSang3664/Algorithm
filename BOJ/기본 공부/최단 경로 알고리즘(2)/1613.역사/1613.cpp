#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 401
#define INF 987654321
#define endl '\n'

int n, k;
int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, a, b;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = -1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (map[i][k] == 1 && map[k][j]== 1) map[i][j] = 1;
				else if (map[i][k] == -1 && map[k][j] == -1) map[i][j] = -1;
			}
		}
	}
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> a >> b;
		cout << map[a][b]*-1 << endl;
	}
	return 0;
}