#include<iostream>

using namespace std;
int map[8][8];
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		for (int i = 0; i < 8; ++i) {
			string temp;
			cin >> temp;
			for (int j = 0; j < 8; ++j) {
				map[i][j] = temp[j] - '0';
			}
		}
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				//가로 검사
				if (map[i][j] == map[i][j + (N - 1)] && j < 8 - (N - 1)) {
					for (int k = 1; k < N - 1; ++k) {
						if (map[i][j + k] != map[i][j + (N - 1) - k]) break;
						if (k == N - 2) {
							cnt++;
						}
					}
				}
				//tpfh 검사
				if (map[i][j] == map[i + (N - 1)][j] && i < 8 - (N - 1)) {
					for (int h = 1; h < N - 1; ++h) {
						if (map[i + h][j] != map[i + (N - 1) - h][j]) break;
						if (h == N - 2) {
							cnt++;
						}
					}
				}
			}
		}
		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}