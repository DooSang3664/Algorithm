#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 1000+3
int n, k;
int L, R, M;
vector<pair<int, int>> v;
bool check[MAX];
double root(pair<int,int> &a, pair<int,int> &b) {
	return ceil(sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2)));
}

bool BFS(int M,int k) {
	memset(check, 0, sizeof(check));
	queue<pair<int, int>>q;
	q.push({0,0});
	while (!q.empty()) {
		int from = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (from == v.size() - 1) {
			if (cnt <= k + 1) return true;
			else return false;
		}
		for (int i = 1; i < v.size(); ++i) {
			if (check[i]) continue;
			if (root(v[i], v[from]) <= M) {
				check[i] = true;
				q.push({ i,cnt + 1 });
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	v.push_back({0,0}); //½ÃÀÛÁÂÇ¥
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	int ans;
	v.push_back({ 10000,10000 });//¸ñÇ¥ÁÂÇ¥
	L = 1; R = root(v[0],v[v.size()-1]);
	while (L <= R) {
		M = (L + R) / 2;
		//cout << M << endl;
		if (BFS(M,k)) {
			R = M - 1;
		}
		else {
			L = M + 1;
		}
	}
	if (L % 10)
		cout << (L / 10) + 1 << endl;
	else
		cout << L/10 << endl;
	return 0;
}