#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9
int N, M;
int map[MAX][MAX];
int copy_map[MAX][MAX];
struct camera {
	int x;
	int y;
	int num;
	int dir;
};
vector<camera> ca;
int out = 987654321;

int min(int x, int y) { return x > y ? y : x; }

void map_copy() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			copy_map[i][j] = map[i][j];
		}
	}
}

int count_map() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {		
			if (copy_map[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void R(int x, int y) {
	for (int i = y; i < M; ++i) {
		if (copy_map[x][i] == 6) break;
		if (1 <= copy_map[x][i] && copy_map[x][i] <= 5) continue;
		copy_map[x][i] = -1;
		
	}
}
void L(int x, int y) {
	for (int i = y; i >= 0; --i) {
		if (copy_map[x][i] == 6) break;
		if (1 <= copy_map[x][i] && copy_map[x][i] <= 5) continue;
		copy_map[x][i] = -1;	
	}
}
void D(int x, int y) {
	for (int i = x; i < N; ++i) {
		if (copy_map[i][y] == 6) break;
		if (1 <= copy_map[i][y] && copy_map[i][y] <= 5) continue;
		copy_map[i][y] = -1;

	}
}
void U(int x, int y) {
	for (int i = x; i >= 0; --i) {
		if (copy_map[i][y] == 6) break;
		if (1 <= copy_map[i][y] && copy_map[i][y] <= 5) continue;
		copy_map[i][y] = -1;
	}
}
void start() {
	map_copy();
	for (int i = 0; i < ca.size(); ++i) {
		if (ca[i].num == 1) {
			if (ca[i].dir == 1) { R(ca[i].x, ca[i].y); }
			else if (ca[i].dir == 2) { L(ca[i].x, ca[i].y); }
			else if (ca[i].dir == 3) { U(ca[i].x, ca[i].y); }
			else if (ca[i].dir == 4) { D(ca[i].x, ca[i].y);}
		}
		else if (ca[i].num == 2) {
			if (ca[i].dir == 1 || ca[i].dir == 2) {
				R(ca[i].x, ca[i].y);
				L(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 3 || ca[i].dir == 4) {
				U(ca[i].x, ca[i].y);
				D(ca[i].x, ca[i].y);
			}
		}
		else if (ca[i].num == 3) {
			if (ca[i].dir == 1) { 
				R(ca[i].x, ca[i].y);
				D(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 2) {
				L(ca[i].x, ca[i].y);
				U(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 3) {
				U(ca[i].x, ca[i].y);
				R(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 4) { 
				L(ca[i].x, ca[i].y);
				D(ca[i].x, ca[i].y);
			}
		}
		else if (ca[i].num == 4) {
			if (ca[i].dir == 1) { 
				R(ca[i].x, ca[i].y);
				D(ca[i].x, ca[i].y);
				U(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 2) {
				L(ca[i].x, ca[i].y);
				D(ca[i].x, ca[i].y);
				U(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 3) {
				U(ca[i].x, ca[i].y);
				R(ca[i].x, ca[i].y);
				L(ca[i].x, ca[i].y);
			}
			else if (ca[i].dir == 4) {
				D(ca[i].x, ca[i].y);
				R(ca[i].x, ca[i].y);
				L(ca[i].x, ca[i].y);
			}
		}
		else if (ca[i].num == 5) {
			R(ca[i].x, ca[i].y);
			D(ca[i].x, ca[i].y);
			U(ca[i].x, ca[i].y);
			L(ca[i].x, ca[i].y);
		}
	}
}
void DFS(int cnt) {
	if (cnt == ca.size()) {
		start();
		int sum = count_map();
		out = min(out, sum);
		return;
	}
	ca[cnt].dir = 1;
	DFS(cnt + 1);
	ca[cnt].dir = 2;
	DFS(cnt + 1);
	ca[cnt].dir = 3;
	DFS(cnt + 1);
	ca[cnt].dir = 4;
	DFS(cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				ca.push_back({i,j,map[i][j],-1});
			}
		}
	}
	DFS(0);
	cout << out << endl;
	return 0;
}
