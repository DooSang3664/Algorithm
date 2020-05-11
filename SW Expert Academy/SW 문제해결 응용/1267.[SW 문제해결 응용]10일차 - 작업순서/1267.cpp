#include<iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1001
vector<int> v[MAX];
int phase[MAX];
queue<int>q;
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		memset(phase, 0, sizeof(phase));
		int V, E;
		cin >> V >> E;
		for (int i = 0; i < E; ++i) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			phase[to]++;
		}
		for (int i = 1; i <= V; ++i) {
			if (phase[i] == 0) {
				q.push(i);
			}
		}
		cout << "#" << test_case << " ";
		while (!q.empty()) {
			int cx = q.front();
			q.pop();
			cout << cx << " ";
			for (int i = 0; i < v[cx].size(); ++i) {
				int nx = v[cx][i];
				phase[nx]--;
				if (phase[nx] == 0) {
					q.push(nx);
				}
			}
		}
		cout << endl;
		for (int j = 1; j <= V; ++j) {
			v[j].clear();
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}