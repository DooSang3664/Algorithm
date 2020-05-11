#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 100000 + 1;
bool visited[MAX];
void bfs(int N, int K) {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;
	while (!q.empty()) {
		int nxet = q.front().first;
		int nxetcount = q.front().second;
		q.pop();
		if (nxet == K) {
			cout << nxetcount << endl;
			break;
		}
		if (nxet + 1 < MAX && visited[nxet + 1] == false) {
			q.push({ nxet + 1, nxetcount + 1 });
			visited[nxet + 1] = true;
		}
		if (nxet - 1 >= 0 && visited[nxet - 1] == false) {
			q.push({ nxet - 1, nxetcount + 1 });
			visited[nxet - 1] = true;
		}
		if (nxet * 2 < MAX && visited[nxet * 2] == false) {
			q.push({ nxet * 2, nxetcount + 1 });
			visited[nxet * 2] = true;
		}
	}
}
int main() {
	int N, K;
	cin >> N >> K;
	bfs(N, K);
	return 0;
}