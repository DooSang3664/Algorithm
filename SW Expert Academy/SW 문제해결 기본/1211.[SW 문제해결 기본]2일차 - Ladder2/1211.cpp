#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct point {
	int x;
	int y;
};
int map[101][101];
bool visited[100][100];
vector<point> start;
int last = 987654321;
int out = 0;
void DFS(int x, int y, int cnt) {
	if (x == 0) {
		if (last > cnt) {
			last = cnt;
			out = y;
		}
		return;
	}
	visited[x][y] = true;
	if (map[x][y + 1] == 1 && visited[x][y + 1] == false) {
		DFS(x, y + 1, cnt + 1);
	}
	else if (map[x][y - 1] == 1 && visited[x][y - 1] == false) {
		DFS(x, y - 1, cnt + 1);
	}
	else {
		DFS(x - 1, y, cnt + 1);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));	
		last = 987654321;
		int N = 0;
		cin >> N;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> map[i][j];
				if (map[99][j] == 1) {
					memset(visited, false, sizeof(visited));
					DFS(i, j, 0);
				}
			}
		}
		cout << "#" << N << " " << out << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
