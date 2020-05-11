#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int N, C;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(0);
	int L=1, R, M;
	int output = 0;
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	R = v[v.size() - 1];
	while (L <= R) {
		M = (L + R) / 2;
		int len = 1;
		int prev = v[0];
		for (int i = 1; i < N; ++i) {
			if (v[i] - prev >= M) {
				len++;
				prev = v[i];
			}
		}
		if (len >= C) {
			output = max(output, M);
			L = M + 1;
		}
		else {
			R = M - 1;
		}

	}
	cout << output << endl;
	return 0;
}