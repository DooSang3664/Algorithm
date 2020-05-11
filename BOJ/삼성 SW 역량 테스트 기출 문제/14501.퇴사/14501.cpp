#include <iostream>
using namespace std;
int max(int x, int y) {
	return x > y ? x : y;
}
int N;
int T[16];
int P[16];
int ans = 0;
void DFS(int day, int sum) {
	if (day == N + 1) {
		ans = max(ans, sum);
		return;
	}
	if (day + T[day] <= N + 1) {
		DFS(day + T[day], sum + P[day]);
	}
	if (day + 1 <= N + 1) {
		DFS(day + 1, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	DFS(1, 0);
	cout << ans << endl;
	return 0;
}
