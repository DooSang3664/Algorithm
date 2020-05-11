#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101
#define INF 987654321
vector<int> v[MAX];
int dist[MAX];
int N;
int m_cost = 0;
int out;
void BFS(int start) {
	queue<pair<int,int>> q;
	dist[start] = 0;
	q.push({ start ,0});
	while (!q.empty()) {
		int cx = q.front().first;
		int c_cost = q.front().second;
		q.pop();
		for (int i = 0; i < v[cx].size(); ++i) {
			int nx = v[cx][i];
			int n_cost = c_cost + 1;
			if (dist[nx] >  n_cost) {
				q.push({ nx,n_cost });
				dist[nx] = n_cost;
				if (m_cost < n_cost) {
					m_cost = n_cost;
				}
			}
		}
	}
	for (int i = MAX; i >= 1; --i) {
		if (dist[i] != INF) {
			if (dist[i] == m_cost) {
				out = i;
				break;
			}
		}
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 1; i <= 100; ++i) {
			v[i].clear();
		}
		for (int i = 1; i <= 100; ++i) {
			dist[i] = INF;
		}
		m_cost = 0;
		out=0;
	    int start;
		cin >> N >> start;
		for (int i = 0; i < N / 2; ++i) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
		}
		BFS(start);
		cout << "#" << test_case << " " << out << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/