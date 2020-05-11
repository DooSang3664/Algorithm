#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1000+1
#define KMAX 100000
int T, N, K,W;
vector<int> v[KMAX];
int phase[MAX];
int time[MAX];
int mamo[MAX];
queue<int>q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; ++i) {		
		cin >> N >> K;
		for (int j = 0; j < K; ++j) {
			v[j].clear();
		}
		memset(mamo, 0, sizeof(mamo));
		memset(time, 0, sizeof(time));
		memset(phase, 0, sizeof(phase));
	
		for (int j = 1; j <= N; ++j) {
			cin >> time[j];
		}

		for (int j = 0; j < K; ++j) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			phase[b]++;
		}
		cin >> W;
		//위상이 0인거 
		for (int j = 1; j <= N; ++j) {
			if (phase[j] == 0) {
				q.push(j);
				mamo[j] = time[j];
			}
		}
		int sum = 0;
		while (!q.empty()) {
			int cx = q.front();
			q.pop();
			for (int j = 0; j < v[cx].size(); ++j) {
				int nx = v[cx][j];
				phase[nx]--;
				mamo[nx] = max(mamo[nx], mamo[cx] + time[nx]);
				if (phase[nx] == 0) {
					q.push(nx);								
				}
			}
		}
		cout << mamo[W] << endl;
	}
	return 0;
}