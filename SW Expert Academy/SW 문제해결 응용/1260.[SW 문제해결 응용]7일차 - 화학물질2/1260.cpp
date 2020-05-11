#include<iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100+1
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector< pair<int, int>> v;
deque<pair<int, int>>dq;
vector<bool>check;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		if (q.empty()) {
			v.push_back({cx - x + 1,cy - y + 1} );
		}
	}
}
void DFS(int cx, int cy) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == cy && check[i] == false) {
			check[i] = true;
			dq.push_back({ v[i].first,v[i].second });
			DFS(v[i].first, v[i].second);
			break;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == cx && check[i] == false) {
			check[i] = true;
			dq.push_front({ v[i].first,v[i].second });
			DFS(v[i].first, v[i].second);
			break;
		}
	}
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		check.clear();
		v.clear();
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (map[i][j] != 0 && visited[i][j] == false) {
					BFS(i, j);
				}
			}
		}
		check.resize(v.size());
		dq.push_back({ v[0].first, v[0].second });
		check[0] = true;
		DFS(v[0].first, v[0].second);
		
		//dq에 대한 계산만 하면 된다
		int map[21][21];
		int d[21] = {0,};
		for (int i = 0; i < dq.size(); ++i) {
			d[i] = dq[i].first;
		}
		d[dq.size()] = dq[dq.size() - 1].second;
		for (int diagonal = 0; diagonal < dq.size(); diagonal++) {
			for (int i = 1; i <= dq.size() - diagonal; i++) {
				int j = i + diagonal;
				if (j == i) {
					map[i][j] = 0;
					continue;
				}
				map[i][j] = 999999;
				for (int k = i; k <= j - 1; k++) {
					map[i][j] = min(map[i][j], map[i][k] + map[k + 1][j] + d[i-1]*d[k]*d[j]);
				}
			}
		}
		//계산법을 못찾겠다
		cout << "#" << test_case << " " << map[1][dq.size()] << endl;
		for (int i = 1; i <= dq.size(); i++)
		{
			for (int j = 1; j <= dq.size(); j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		while (!dq.empty()) {
			dq.pop_back();
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}