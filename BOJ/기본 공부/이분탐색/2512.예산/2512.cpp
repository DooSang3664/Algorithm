#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int N,M;
vector<int>map;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int output = 0;
	int L=1, R=1, S;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		map.push_back(temp);
		R = max(R, temp);
	}
	cin >> M;
	while (L <= R) {
		S = (L + R) / 2;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			if (S <= map[i]) {
				sum += S;
			}
			else if (S > map[i]) {
				sum += map[i];
			}
		}
		if (sum > M) {
			R = S - 1;
		}
		else {
			output = max(output, S);
			L = S + 1;
		}
	}
	cout << output << endl;
	return 0;
}