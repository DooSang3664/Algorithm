#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define max 25 + 1

int N;
int map[max][max];
bool check[max][max];
vector<int>v;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int x,int y) {
	int count = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty()) {
		count++;
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();		
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == 1 && check[nx][ny] == false) {
					q.push({ nx,ny });
					check[nx][ny] = true;					
				}
			}
		}
	}
	v.push_back(count);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; ++j) {
			map[i][j] = temp[j] - '0';
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 1 && check[i][j] == false) {
				BFS(i, j);
			}
		}
	}
	sort(v.begin(), v.end());

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}

	return 0;
}