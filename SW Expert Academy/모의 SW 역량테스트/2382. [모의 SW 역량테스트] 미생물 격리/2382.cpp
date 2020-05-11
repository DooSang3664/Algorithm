#include<iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1000+1
int N, M, K;
struct vi {
	int x;
	int y;
	int size;
	int dir;
};
vi pin[MAX];
int map[100][100][2];
int dx[5] = { 0, -1, 1, 0, 0};
int dy[5] = { 0, 0, 0, -1, 1};
int ch_dir[5] = { 0,2,1,4,3 };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		for (int i = 1; i <= K; ++i) {
			int x, y, m, dir;
			cin >> pin[i].x >> pin[i].y >> pin[i].size >> pin[i].dir;
		}
		while (M--) {
			memset(map, 0, sizeof(map));
			for (int i = 1; i <= K; ++i) {
				if (pin[i].size == 0) continue;
				//이동
				pin[i].x += dx[pin[i].dir];
				pin[i].y += dy[pin[i].dir];
				//위치 확인
				if (pin[i].x == 0 || pin[i].x == N - 1 || pin[i].y == 0 || pin[i].y == N - 1) {
					pin[i].dir = ch_dir[pin[i].dir];
					pin[i].size = pin[i].size / 2;
				}
				if (map[pin[i].x][pin[i].y][0]) {
					int idx = map[pin[i].x][pin[i].y][0];
					pin[idx].size += pin[i].size;
					if (map[pin[i].x][pin[i].y][1] < pin[i].size) {
						map[pin[i].x][pin[i].y][1] = pin[i].size;
						pin[idx].dir = pin[i].dir;
					}
					pin[i].size = 0;
				}
				else {
					map[pin[i].x][pin[i].y][0] = i;
					map[pin[i].x][pin[i].y][1] = pin[i].size;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= K; ++i) {
			sum += pin[i].size;
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}