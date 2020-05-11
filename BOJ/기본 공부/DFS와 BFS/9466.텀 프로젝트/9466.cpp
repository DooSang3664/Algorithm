#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100001
int T, n,cnt;
int tim[MAX];
bool check[MAX];
bool stop[MAX];
void DFS(int cx){
	check[cx] = true;
	int nx = tim[cx];
	if (check[nx] == false)
		DFS(nx);
	else if (stop[nx] == false) {
		for (int i = nx; i != cx; i = tim[i]) {
			cnt++;
		}
		cnt++;
	}
	stop[cx] = true;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		memset(check, false, sizeof(check));
		memset(stop, false, sizeof(stop));
		cin >> n;
		for (int j = 1; j <= n; ++j) {
			cin >> tim[j];
		}
		cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (check[j] == false)
				DFS(j);
		}
		cout << n-cnt << endl;
	}

	return 0;
}