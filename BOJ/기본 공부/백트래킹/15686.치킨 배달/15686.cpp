#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 51

int N, M;
int map[MAX][MAX];
bool check[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> V;
int output = 9999999;

void DFS(int num,int idx) {
	if (num == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); ++i) {
			int hx = house[i].first;
			int hy = house[i].second;
			int temp = 9999999;
			for (int j = 0; j < chicken.size(); ++j) {
				if (check[j]) {
					int cx = chicken[j].first;
					int cy = chicken[j].second;
					int Distance = abs(hx - cx) + abs(hy - cy);
					temp = min(temp, Distance);
				}
			}
			sum += temp;
		}
		output = min(output, sum);
		return;
	}
	if (idx == chicken.size())
		return;

	check[idx] = true;
	DFS(num + 1,idx+1 );
	check[idx] = false;
	DFS(num, idx + 1);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i,j });
			else if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	DFS(0, 0);
	cout << output << endl;
	return 0;
}