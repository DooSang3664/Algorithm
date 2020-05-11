#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int K, N;
vector<long long> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	long long  L = 1, R = 0;
	for (int i = 0; i < K; ++i) {
		long long temp;
		cin >> temp;
		v.push_back(temp);
		R = max(R, temp);
	}
	long long len = 0;
	long long  M;
	while (L <= R) {
		int sum = 0;
		M = (L + R) / 2;
		for (int i = 0; i < K; ++i) {
			sum += v[i] / M;
		}
		if (sum >= N) {
			len = max(len, M);
			L = M + 1;
		}
		else {
			R = M - 1;
		}
	}
	cout << len << "\n";
	return 0;
}