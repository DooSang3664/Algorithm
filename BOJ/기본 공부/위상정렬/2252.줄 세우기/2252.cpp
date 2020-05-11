#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define MAX 32001

vector<int> v[MAX];
queue<int> q;
int mamo[MAX];
int N, M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		mamo[i] = 0;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		mamo[b]++;
	}
	//위상이 0인거 넘어주기
	for (int i = 1; i <= N; ++i) {
		if(mamo[i]==0)
			q.push(i);
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << ' ';
		for (int i = 0; i < v[temp].size(); ++i) {
			mamo[v[temp][i]]--;
			if (mamo[v[temp][i]] == 0)
				q.push(v[temp][i]);
		}
	}
	return 0;
}