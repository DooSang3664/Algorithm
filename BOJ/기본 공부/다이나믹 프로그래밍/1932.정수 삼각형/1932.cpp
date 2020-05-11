#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500+1

int N;
int map[MAX][MAX];
int check[MAX][MAX] = { 0, };

int DP(int cnt, int num) {
	if (check[cnt][num] != 0)
		return check[cnt][num];
	if (cnt == N - 1) {
		return map[cnt][num];
	}
	return check[cnt][num] = max(DP(cnt + 1, num), DP(cnt + 1, num + 1)) + map[cnt][num];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> map[i][j];
		}
	}
	cout << DP(0, 0) << endl;
	return 0;
}