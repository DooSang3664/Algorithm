#include<iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
#define MAX 11

int N, M, C;
int map[MAX][MAX];
int visitied[MAX];
int maxsum[2];
vector<int> box[2];
int out = 0;

void solve(int num,int x,int sum) {
	if (sum > C) return;
	//다 더하기
	int tempsum = 0;
	for (int i = 0; i < M; ++i) {
		if (visitied[i] == true) {
			tempsum += pow(box[num][i], 2);
		}
	}
	if (maxsum[num] < tempsum) {
		maxsum[num] = tempsum;
	}
	for (int i = x; i < M; ++i) {
		visitied[i] = true;
		solve(num, i + 1, sum + box[num][i]);
		visitied[i] = false;
	}
}

void DFS(int cnt,int posx,int posy) {
	if (cnt == 2) {
		for (int i = 0; i < 2; ++i) {
			maxsum[i] = 0;
			solve(i, 0, 0);
		}
		int sum = maxsum[0] + maxsum[1];
		if (out < sum) {
			out = sum;
		}
		return;
	}
	for (int i = posx; i < N; ++i, posy = 0) {	
		for (int j = posy; j < N-M+1; ++j) {
			for (int st = j; st < j + M; ++st) {
				box[cnt].push_back(map[i][st]);
			}
			DFS(cnt + 1, i, j + M);
			box[cnt].clear();
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
		out = 0;
		cin >> N >> M >> C;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}
		DFS(0,0,0);
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;
}