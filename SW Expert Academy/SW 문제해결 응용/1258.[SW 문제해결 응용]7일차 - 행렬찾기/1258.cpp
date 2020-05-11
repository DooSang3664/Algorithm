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
vector<pair<int,pair<int, int>>> v;
void BFS(int x,int y) {
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
			if (nx > 0 && ny > 0 && nx <= N && ny <= N){
				if (visited[nx][ny] == false && map[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		if (q.empty()) {
			v.push_back({ (cx - x + 1)*(cy - y + 1),{cx - x + 1,cy - y + 1} });
		}
	}
}
bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
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
		sort(v.begin(), v.end(), cmp);
		cout << "#" << test_case << " " << v.size() << " ";
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i].second.first << " " << v[i].second.second << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}