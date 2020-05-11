#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	int sum = 0;
	if (pq.size() == 1) {
		cout << 0 << '\n';
		return 0;
	}
	while (!pq.empty()) {
		int q1 = pq.top(); pq.pop();
		int q2 = pq.top(); pq.pop();
		sum += q1 + q2;
		if (pq.empty()) {
			break;
		}
		pq.push(sum);
	}
	cout << sum << '\n';
	return 0;

}
