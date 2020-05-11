#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>map[11][11];
int M, A;
vector<int>man[2];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };


bool visited[11][11];
int sum1 = 0;
int sum2 = 0;
void map_BFS(int x, int y, int c, int p) {
	queue<pair<pair<int, int>, int>> q;
	visited[x][y] = true;
	q.push({ { x,y }, 0 });
	map[x][y].push_back(p);
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (dist >= c) break;
		for (int i = 1; i <= 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > 0 && ny > 0 && nx <= 10 && ny <= 10) {
				if (visited[nx][ny] == false) {
					q.push({ {nx,ny},dist + 1 });
					visited[nx][ny] = true;
					map[nx][ny].push_back(p);
				}
			}
		}
	}
}
void men_BFS(int x1, int y1, int x2, int y2) {
	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;
	q1.push({ x1,y1 });
	q2.push({ x2,y2 });
	int time = -1;
	while (!q1.empty() && !q2.empty()) {
		time++;
		int cx1 = q1.front().first;
		int cy1 = q1.front().second;
		int cx2 = q2.front().first;
		int cy2 = q2.front().second;
		q2.pop();
		q1.pop();
		//두명이 같은 곳일때 <- 여기가 틀렸을꺼임
		if (map[cx1][cy1].size() != 0 || map[cx2][cy2].size() != 0) {
			if (cx1 == cx2 && cy1 == cy2) {
				//접속할곳이 2개이상
				if (map[cx1][cy2].size() > 1) {
					int temp = 0, num = 0;
					for (int i = 0; i < map[cx1][cy1].size(); ++i) {
						if (temp < map[cx1][cy1][i]) {
							temp = map[cx1][cy1][i];
							num = i;
						}
					}
					bool flag = false;
					int check = 0;
					temp = temp / 2;
					for (int i = 0; i < map[cx1][cy1].size(); ++i) {
						if (i != num) {
							if (temp < map[cx1][cy1][i]) {
								flag = true;
								check = i;
							}
						}
					}
					if (flag == true) {
						sum1 += map[cx1][cy1][num];
						sum2 += map[cx1][cy1][check];
					}
					else {
						sum1 += map[cx1][cy1][num] / 2;
						sum2 += map[cx1][cy1][num] / 2;
					}
				}
				// 한개
				else if (map[cx1][cy1].size() == 1) {
					sum1 += map[cx1][cy1][0] / 2;
					sum2 += map[cx1][cy1][0] / 2;
				}

			}
			//두명이 다른 곳일때
			else {
				int temp1 = 0;
				for (int i = 0; i < map[cx1][cy1].size(); ++i) {
					if (temp1 < map[cx1][cy1][i]) {
						temp1 = map[cx1][cy1][i];
					}
				}
				int temp2 = 0;
				for (int i = 0; i < map[cx2][cy2].size(); ++i) {
					if (temp2 < map[cx2][cy2][i]) {
						temp2 = map[cx2][cy2][i];
					}
				}
				if (temp1 == temp2) {
					int temp11 = 0;
					for (int i = 0; i < map[cx1][cy1].size(); ++i) {
						if (temp1 != map[cx1][cy1][i] && temp11 < map[cx1][cy1][i])
							temp11 = map[cx1][cy1][i];
					}
					int temp22 = 0;
					for (int i = 0; i < map[cx2][cy2].size(); ++i) {
						if (temp1 != map[cx2][cy2][i] && temp22 < map[cx2][cy2][i])
							temp22 = map[cx2][cy2][i];
					}
					if (temp11 > temp22) {
						if (temp11 > temp1 / 2) {
							sum1 += temp11;
							sum2 += temp2;
						}
					}
					else if (temp11 < temp22) {
						if (temp22 > temp1 / 2) {
							sum1 += temp1;
							sum2 += temp22;
						}
					}
					else {
						if (temp11 > temp1 / 2) {
							sum1 += temp11;
							sum2 += temp1;
						}
						else {
							sum1 += temp1 / 2;
							sum2 += temp2 / 2;
						}
					}
				}
				else {
					sum1 += temp1;
					sum2 += temp2;
				}
			}
		}
		if (time < M) {
			int nx1 = cx1 + dx[man[0][time]];
			int ny1 = cy1 + dy[man[0][time]];
			int nx2 = cx2 + dx[man[1][time]];
			int ny2 = cy2 + dy[man[1][time]];
			q1.push({ nx1,ny1 });
			q2.push({ nx2,ny2 });
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 2; ++i) {
			man[i].clear();
		}
		for (int i = 0; i < 11; ++i) {
			for (int j = 0; j < 11; ++j) {
				map[i][j].clear();
			}
		}
		sum1 = 0;
		sum2 = 0;
		cin >> M >> A;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < M; ++j) {
				int temp;
				cin >> temp;
				man[i].push_back(temp);
			}
		}
		for (int i = 0; i < A; ++i) {
			memset(visited, 0, sizeof(visited));
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			map_BFS(y, x, c, p);
		}
		men_BFS(1, 1, 10, 10);
		cout << "#" << test_case << " " << sum1 + sum2 << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}