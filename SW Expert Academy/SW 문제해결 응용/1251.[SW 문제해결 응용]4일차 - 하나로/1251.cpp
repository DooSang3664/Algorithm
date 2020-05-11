#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 1000
struct Point
{
	int x;
	int y;
	int num;
};
vector<Point> v;
vector < pair<double, pair<int, int>>>map;
double E;
int parent[MAX];

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
bool Unioncheck(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return true;
	}
	else {
		return false;
	}
}

double Distance(Point a,Point b) {
	int x = abs(a.x - b.x);
	int y = abs(a.y - b.y);
	return E*pow(sqrt(pow(x, 2) + pow(y, 2)),2);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << fixed;
		cout.precision(0);
		int N;
		cin >> N;
		v.clear();
		v.resize(N);
		map.clear();
		for (int i = 0; i < N; ++i) {
			cin >> v[i].x;
			v[i].num = i;
		}
		for (int i = 0; i < N; ++i) {
			cin >> v[i].y;
		}
		cin >> E;
		for (int i = 0; i < MAX; ++i) {
			parent[i] = i;
			
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i+1; j < N; ++j) {
				map.push_back({ Distance(v[i],v[j]),{v[i].num,v[j].num} });
			}
		}
		sort(map.begin(), map.end());
		double sum = 0;
		for (int i = 0; i < map.size(); ++i) {
			int from = map[i].second.first;
			int to = map[i].second.second;
			if(Unioncheck(from,to) == false) {
				Union(from, to);
				sum += map[i].first;
			}
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}