#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>>v;
deque<pair<int, int>>dq;
int N;
bool visited[20];
void DFS(int cx, int cy) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == cy && visited[i] == false) {
			visited[i] = true;
			dq.push_back({ v[i].first,v[i].second });
			DFS(v[i].first, v[i].second);
			break;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == cx && visited[i] == false) {
			visited[i] = true;
			dq.push_front({ v[i].first,v[i].second });
			DFS(v[i].first, v[i].second);
			break;
		}
	}
	return;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		v.clear();
		memset(visited, false, sizeof(visited));
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		dq.push_back({ v[0].first, v[0].second });
		visited[0] = true;
		DFS(v[0].first, v[0].second);
		cout << "#" << test_case << " ";
		for (int i = 0; i < dq.size(); ++i) {
			cout << dq[i].first << " " << dq[i].second << " ";
		}
		cout << endl;
		while (!dq.empty()) {
			dq.pop_back();
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}