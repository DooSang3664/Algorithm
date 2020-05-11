#include <iostream>
#define N_MAX 200+1
#define M_MAX 1000+1
#define endl '\n'
using namespace std;
int N, M;
int parent[M_MAX];
int root[N_MAX];

int Find(int x) { // x�� ���� ������ Root��带 ��ȯ
	if (x == parent[x]) {
		return x;
	}
	else {
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}
void Union(int x, int y) { // x���ҿ� y���Ҹ� ��ġ�� �Լ��� y�� Root��带 x�� �Ѵ�.
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				Union(i, j);
			}
		}
	}

	int start;
	bool ok = true;
	for (int i = 1; i <= M; ++i) {
		int temp;
		cin >> temp;
		if (i == 1)
			start = Find(temp);
		else {
			if (start != Find(temp)) {
				ok = false;
				break;
			}
		}
	}

	
	if (ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}