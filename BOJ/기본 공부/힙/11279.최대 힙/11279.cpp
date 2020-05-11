#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		if (!temp && pq.empty()) {
			cout << 0 << "\n";
		}
		else if (!temp) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else {
			pq.push(temp);
		}
	}
	return 0;
}
