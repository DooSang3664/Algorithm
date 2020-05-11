#include <iostream>
using namespace std;
#define MAX 21
int N;
int map[MAX][MAX];
bool check[MAX];
int gad = 100;

void DFS(int Tmenber,int cnt) {
	if (Tmenber == N/2) {
		int start = 0; int link = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if(check[i] && check[j])
					start += map[i][j];
				else if(!check[i] && !check[j])
					link += map[i][j];
			}
		}
		int temp = abs(start - link);
		if (gad > temp) gad = temp;
		return;
	}
	for (int i = cnt; i < N; ++i) {
		check[i] = true;
		DFS(Tmenber + 1, i + 1);
		check[i] = false;
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	DFS(0, 0);
	cout << gad << endl;
	return 0;

}