#include <iostream>
#define MAX 1000000+1
#define endl '\n'
using namespace std;
int n, m;
int parent[MAX];

int Find(int x) { // x로 들어온 원소의 Root노드를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}
void Union(int x, int y) { // x원소와 y원소를 합치는 함수로 y의 Root노드를 x로 한다.
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	int c, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> c >> a >> b;
		if (!c) {
			Union(a, b);
		}
		else {
			int pa = Find(a);
			int pb = Find(b);
			if (pa ==pb)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}