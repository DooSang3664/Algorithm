#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[100][100];
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}
		//1은 아래로 2는 위로 
		for (int j = 0; j < N; ++j) {
			for (int i = 0; i < N; ++i) {
				if (map[i][j] == 2) {
					map[i][j] = 0;
				}
				else if (map[i][j] == 1) {
					break;
				}
			}
			for (int i = N - 1; i >= 0; --i) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
				}
				else if (map[i][j] == 2) {
					break;
				}
			}
		}
		for (int j = 0; j < N; ++j) {
			bool flag = false;
			for (int i = 0; i < N; ++i) {
				if (map[i][j] == 1) {
					if (flag == false) {
						flag = true;
					}
				}
				else if (map[i][j] == 2) {
					if (flag == true) {
						flag = false;
						cnt++;
					}
				}
			}
		}
		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}