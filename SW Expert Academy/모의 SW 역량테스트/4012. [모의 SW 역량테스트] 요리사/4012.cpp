#include<iostream>
#include <cstring>
using namespace std;
#define MAX 16+1
int N;
int map[MAX][MAX];
bool check[MAX];
int out;
void solve(int pos,int cnt) {
	if (pos == N / 2) {
		int tim1=0, tim2=0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (check[i] && check[j]) {
					tim1 += map[i][j];
				}
				else if (!check[i] && !check[j]) {
					tim2 += map[i][j];
				}
			}
		}
		int sum = abs(tim1 - tim2);
		if (out > sum) {
			out = sum;
		}
		return;
	}
	for (int i = cnt; i < N; ++i) {
		check[i] = true;
		solve(pos + 1,i+1);
		check[i] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(check, 0, sizeof(check));
		out = 987654321;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}
		solve(0, 0);
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}