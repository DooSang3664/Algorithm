#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
	int N, temp;
	int ans=0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		ans = max(ans, v[i] * (N-i));
	}
	cout << ans << endl;
	return 0;
}