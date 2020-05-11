#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> min;
	priority_queue<int, vector<int>, less<int>> max;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		if (max.size() == 0) {
			max.push(temp);
		}
		else {
			if (max.size() > min.size()) {
				min.push(temp);
			}
			else {
				max.push(temp);
			}
			if (max.top() > min.top()) {
				int max_temp = max.top();
				int min_temp = min.top();
				max.pop();
				min.pop();
				max.push(min_temp);
				min.push(max_temp);
			}
		}
		cout << max.top() << "\n";
	}
	return 0;
}