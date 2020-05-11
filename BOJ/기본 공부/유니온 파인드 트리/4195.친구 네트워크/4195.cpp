#include <iostream>
#include <map>
#define MAX 200000+1
#define endl '\n'
using namespace std;
int parent[MAX];
int check[MAX];
int T, F;

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
int Union(int x, int y) { // x���ҿ� y���Ҹ� ��ġ�� �Լ��� y�� Root��带 x�� �Ѵ�.
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
		check[x] += check[y];
		check[y] = 1;
	}
	return check[x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> F;
		for (int i = 1; i <= F*2; ++i) {
			parent[i] = i;
			check[i] = 1;
		}
		map<string, int> map;
		int cnt = 1;
		for (int i = 1; i <= F; ++i) {
			string temp1, temp2;
			cin >> temp1 >> temp2;			
			if (map.count(temp1) == 0)
				map[temp1] = cnt++;
			if (map.count(temp2) == 0)
				map[temp2] = cnt++;			
			cout << Union(map[temp1], map[temp2]) << endl;
		}
	}
	return 0;
}