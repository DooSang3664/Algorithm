#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>>v;

int main() {	
	int x, y;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		v.push_back({y,x});
	}
	sort(v.begin(),v.end());
	int tag = 0; int count = 0;
	for (int i = 0; i < v.size(); i++) {
		int temp_Begin = v[i].second;
		int temp_End = v[i].first;
		if (tag <= temp_Begin) {
			tag = temp_End;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
/*
input:
11
1 4 <-
3 5
0 6
5 7 <-
3 8
5 9
6 10
8 11 <-
8 12
2 13
12 14 <-

output:
4
*/