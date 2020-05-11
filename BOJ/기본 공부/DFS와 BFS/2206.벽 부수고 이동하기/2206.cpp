#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001
int N, M;
int map[MAX][MAX];
bool check[MAX][MAX][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int BFS(int x, int y) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {x,y},{0,1 } });
	check[x][y][0] = true;
	while (!q.empty()) {
		int cx = q.front().first.first; 
		int cy = q.front().first.second;
		int Bk = q.front().second.first; 
		int cnt = q.front().second.second; 
		q.pop();
		if (cx == N - 1 && cy == M - 1) {
			return cnt;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				//벽일때
				if (map[nx][ny] == 1) {
					if (Bk == 0) {
						check[nx][ny][Bk+1] = true;
						q.push({ {nx,ny},{Bk +1,cnt + 1 }});
					}
				}				
				//벽이 아닐떄
				else {
					if (check[nx][ny][Bk] == false) {
						check[nx][ny][Bk] = true;
						q.push({ {nx,ny},{Bk,cnt + 1 } });						
					}
				}
			}		
		}
	}	
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			map[i][j] = s[j] - '0';
		}
	}
	cout << BFS(0, 0) << endl;
	return 0;
}