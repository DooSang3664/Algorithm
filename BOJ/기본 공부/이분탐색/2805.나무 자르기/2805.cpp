#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int  N, M;
vector<int> tree;

int search(int low, int high) {
	long long output = 0;
	while (low <= high) {
		long long m = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; ++i) {
			if ((tree[i] - m) > 0) {
				sum += (tree[i] - m);	
			}
		}
		if (sum >= M) {
			output = max(output, m);
			low = m + 1;
		}
		else {
			high = m - 1;
		}	
	}
	return output;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	long long low = 1, high = 0;
	for (int i = 0; i < N; ++i) {
		long long temp;
		cin >> temp;
		tree.push_back(temp);
		high = max(high, temp);
	}
	cout << search(low, high);
	return 0;
}