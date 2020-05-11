#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

using namespace std;

vector<int> road;
vector<int> coast;
int n;
long long sum;

priority_queue<int, vector<int>, greater<int> > pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int temp;
	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		road.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coast.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		pq.push(coast[i]);
		sum += (long long)road[i] * (long long)pq.top();
	}

	cout << sum << endl;
	return 0;
}
/*
* priority_queue(heap).

intput:
4
2 3 1
5 2 4 1

output:
18

intput:
4
3 3 4
1 1 1 1

output:
10
*/