#include<iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
struct Point {
	int x;
	int y;
};

Point st, ed, node[10];
bool visited[10];
int N;
int dist = 0;
int m_dist = 0;
void DFS(int x,int y,int cnt) {
	if (cnt == N) {
		dist += abs(ed.x - x) + abs(ed.y - y);
		if (m_dist > dist) {
			m_dist = dist;
		}
		dist -= abs(ed.x - x) + abs(ed.y - y);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (visited[i] == false) {
			visited[i] = true;
			dist += abs(x - node[i].x) + abs(y - node[i].y);
			DFS(node[i].x, node[i].y, cnt + 1);
			dist -= abs(x - node[i].x) + abs(y - node[i].y);
			visited[i] = false;
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
		m_dist = 9874654321;
		cin >> N;
		cin >> st.x >> st.y;
		cin >> ed.x >> ed.y;
		for (int i = 0; i < N; ++i) {
			cin >> node[i].x >> node[i].y;
		}
		DFS(st.x, st.y, 0);
		cout << "#" << test_case << " " << m_dist << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}