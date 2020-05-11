#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 11

int map[MAX][MAX];
int copy_map[MAX][MAX];
int N, M, K; // N : ¶¥ÀÇ Å©±â , M: ³ª¹« °¹¼ö, K : ³âµµ
int up;
vector<int>T[MAX][MAX];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void string_summer() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (T[i][j].size() != 0) {
				int Energy = 0;
				bool ok = true;
				int end = -1;
				for (int t = T[i][j].size()-1; t >=0; --t) {
					if (map[i][j] >= T[i][j][t]) {
						map[i][j] -= T[i][j][t];
						T[i][j][t]++;
					}
					else {
						if (ok)
							end = t;
						ok = false;
						Energy += T[i][j][t] / 2;
					}
				}
				if (end != -1) {
					T[i][j].erase(T[i][j].begin(), T[i][j].begin() + end + 1);
				}
				map[i][j] += Energy;
			}
		}
	}
}
void autumn() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (T[i][j].size() != 0) {
				for (int t = 0; t < T[i][j].size(); ++t) {
					if (T[i][j][t] % 5 == 0) {
						for (int a = 0; a < 8; ++a) {
							int nx = i + dx[a];
							int ny = j + dy[a];
							if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
								T[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			map[i][j] += copy_map[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	int temp;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> temp;
			map[i][j] = 5;
			copy_map[i][j] = temp;
		}
	}

	for (int i = 0; i < M; ++i) {
		int x, y, old;
		cin >> x >> y >> old;
		T[x][y].push_back(old);
	}
	while (K--) {
		string_summer();
		autumn();
		winter();
	}
	int size = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			size += T[i][j].size();
		}
	}
	cout << size << endl;
	return 0;
}
