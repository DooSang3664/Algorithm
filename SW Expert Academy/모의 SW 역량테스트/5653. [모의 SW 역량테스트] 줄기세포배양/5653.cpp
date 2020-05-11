#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000
struct point {
	int x;
	int y;
	int num;
	int time;
};
int N, M, K;
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<point>q;//비활성세포
priority_queue<pair<pair<int,int>,pair<int,int>>>qq; // 활성새포
priority_queue<pair<pair<int, int>, pair<int, int>>>temp; // 저장용
int dx[4] = { 1,-1,0,0, };
int dy[4] = { 0,0,1,-1 };
int out = 0;
void BFS() {
	while (K--) {		
		int size = q.size();		
		for (int i = 0; i < size; ++i) {
			int cx = q.front().x;
			int cy = q.front().y;
			int c_num = q.front().num;
			int c_time = q.front().time;
			q.pop();
			if (c_num == c_time+1) {
				qq.push({ {c_num,0},{cx,cy} });
			}
			else {
				q.push({ cx,cy,c_num,c_time + 1 });
			}
		}
		int qq_size = qq.size();
		for (int i = 0; i < qq_size; ++i) {
			int cx = qq.top().second.first;
			int cy = qq.top().second.second;
			int c_num = qq.top().first.first;
			int c_time = qq.top().first.second;
			qq.pop();
			if (c_time == 1) {
				for (int j = 0; j < 4; ++j) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (visited[nx][ny] == false) {
						q.push({ nx,ny,c_num,0 });
						visited[nx][ny] = true;

					}
				}
			}

			if (c_time == 0  ) {
				temp.push({ {c_num,c_time + 1}, {cx,cy} });
			}
			else if (c_num > c_time) {
				temp.push({ {c_num,c_time + 1}, {cx,cy} });
				continue;
			}
		}
		while (!temp.empty()) {
			qq.push(temp.top());
			temp.pop();
		}
	}

	out = q.size() + qq.size();
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		memset(visited, 0, sizeof(visited));
		out = 0;
		for (int i = 450; i < N+450; ++i) {
			for (int j = 450; j < M+450; ++j) {
				cin >> map[i][j];
				if (map[i][j] != 0) {
					q.push({ i,j,map[i][j],0 });
					visited[i][j] = true;
				}
			}
		}
		BFS();
		cout <<"#" << test_case << " " << out << endl;
		while (!q.empty()) {
			q.pop();
		}
		while (!qq.empty()) {
			qq.pop();
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}