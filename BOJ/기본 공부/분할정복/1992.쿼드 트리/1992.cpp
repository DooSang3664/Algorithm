#include <iostream>
#define MAX 65
#define endl '\n'

using namespace std;
int N;
int map[MAX][MAX];
void funtion(int n, int x, int y) {
	bool zero = true;
	bool one = true;
	for (int i = x; i < n+x; ++i) {
		for (int j = y; j < n+y; ++j) {
			if (map[i][j]) {
				zero = false;
			}
			else {
				one = false;
			}
		}
	}
	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		funtion(n / 2, x, y);
		funtion(n / 2, x, y + (n / 2));
		funtion(n / 2, x+(n/2), y);	
		funtion(n / 2, x+(n/2), y+(n/2));
		cout << ")";
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			map[i][j] = s[j] - '0';
		}
	}
	funtion(N,0,0);
	return 0;
}