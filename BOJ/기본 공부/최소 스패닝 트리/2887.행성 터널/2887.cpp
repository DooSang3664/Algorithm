#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define MAX 100001

using namespace std;

struct star
{
	int num, x, y, z;
};
vector<star> v; // x,y,z
vector<pair<int, pair<int, int>>>map; // cost,from,to
int parent[MAX];
int N;

bool xcmp(star &a,star &b) {
	if (a.x < b.x) return true;
	return false;
}

bool ycmp(star& a, star& b) {
	if (a.y < b.y) return true;
	return false;
}

bool zcmp(star& a, star& b) {
	if (a.z < b.z) return true;
	return false;
}
int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

bool CheckUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}
int Distance(star v1, star v2) {
	int x = abs(v1.x- v2.x);
	int y = abs(v1.y - v2.y);
	int z = abs(v1.z - v2.z);
	return min(z,min(x, y));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < N; ++i) {
		star s;
		s.num = i; // 별 인덱스
		cin >> s.x >> s.y >> s.z;
		v.push_back(s);
	}
	//x기준으로 정렬
	sort(v.begin(), v.end(),xcmp);
	for (int i = 1; i < N; ++i)
		map.push_back({ Distance(v[i-1],v[i]),{v[i-1].num,v[i].num} });
	//y기준으로 정렬
	sort(v.begin(), v.end(), ycmp);
	for (int i = 1; i < N; ++i)
		map.push_back({ Distance(v[i-1],v[i]),{v[i-1].num,v[i].num} });
	//z기준으로 정렬
	sort(v.begin(), v.end(), zcmp);
	for (int i = 1; i < N; ++i)
		map.push_back({ Distance(v[i-1],v[i]),{v[i-1].num,v[i].num} });

	sort(map.begin(), map.end());
	int cnt = 0;
	for (int i = 0; i < map.size(); ++i) {
		int x = map[i].second.first;
		int y = map[i].second.second;		
		if (CheckUnion(x, y) == false) {
			Union(x, y);
			cnt += map[i].first;
		}
	}
	cout << cnt << endl;
	return 0;
}