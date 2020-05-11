#include <iostream>
using namespace std;
int T, N;
int cnt;

void funtion(int sum) {
	if (sum == N) {
		cnt++;
		return;
	}
	if (sum > N) {
		return;
	}
	for (int i = 1; i < 4; ++i) {
		sum += i;	
		funtion(sum);
		sum -= i;
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		funtion(0);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}