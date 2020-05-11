#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 32001
#define endl '\n'

int N, M;
vector<int> v[MAX];
int phase[MAX];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		phase[b]++;
	}
	for (int i = 1; i <= N; ++i) {
		if (phase[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cx = pq.top();
		pq.pop();
		cout << cx << " ";
		for (int i = 0; i < v[cx].size(); ++i) {
			int nx = v[cx][i]; phase[nx]--;
			if (phase[nx] == 0)
				pq.push(nx);
		}
	}
	return 0;
}