#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 21
#define INF 100
struct shark
{
	int x;
	int y;
	int size;
	int time;
	int num;
};
int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

shark S;
vector<pair<int,pair<int, int>>>pish; // x,y,dist


void BFS() {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { S.x, S.y } ,0});
	visited[S.x][S.y] = true;
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int c_time = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
				if (visited[nx][ny] == false) {
					if (map[nx][ny] == 0) {
						visited[nx][ny] = true;
						q.push({ {nx,ny},c_time + 1 });
					}
					else if (map[nx][ny] < S.size) {
						pish.push_back({ c_time + 1,{nx,ny} });
						visited[nx][ny] = true;
						q.push({ {nx,ny},c_time + 1 });
					}
					else if (map[nx][ny] == S.size) {
						visited[nx][ny] = true;
						q.push({ {nx,ny},c_time + 1 });
					}
				}				
			}
		}
	}
}

bool cmp(const pair<int, pair<int, int>>&a, const pair<int, pair<int, int>>&b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	S.size = 2;
	S.num = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				S.x = i;
				S.y = j;
			}
		}	
	}
	while(1) {
		pish.clear();
		memset(visited, 0, sizeof(visited));
		BFS();
		if (pish.size() == 0) {
			cout << S.time << endl;
			return 0;
		}
		else if (pish.size() == 1) {
			map[S.x][S.y] = 0;
			S.x = pish[0].second.first;
			S.y = pish[0].second.second;
			S.num++;
			S.time += pish[0].first;
			map[S.x][S.y] = 9;
			if (S.num == S.size) {
				S.size++;
				S.num = 0;
			}
		}
		else {
			sort(pish.begin(), pish.end(),cmp);
			map[S.x][S.y] = 0;
			S.x = pish[0].second.first;
			S.y = pish[0].second.second;
			S.num++;
			S.time += pish[0].first;
			map[S.x][S.y] = 9;
			if (S.num == S.size) {
				S.size++;
				S.num = 0;
			}
		}
	}
	return 0;
}