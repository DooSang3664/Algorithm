#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int N, K;
vector<pair<int, int>> j;
vector<int> b;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		j.push_back({ m,v });
	}
	for (int i = 0; i < K; i++) {
		int m;
		cin >> m;
		b.push_back(m);
	}
	sort(j.begin(), j.end());
	sort(b.begin(), b.end());

	long long sum = 0;
	int id = 0;
	for (int i = 0; i < K; i++) {
		while (id < N && j[id].first <= b[i]) {
			pq.push(j[id++].second);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << "\n";
	return 0;
}