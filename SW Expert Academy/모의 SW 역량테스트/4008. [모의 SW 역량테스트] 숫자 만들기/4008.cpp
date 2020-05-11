#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int d[4];
vector<int> v;
vector<int> q;
void sovle(int num, int sum, int p, int m, int g, int n) {
	if (num == N) {
		q.push_back(sum);
		return;
	}
	if (p != 0) {
		sovle(num + 1, sum + v[num], p - 1, m, g, n);
	}
	if (m != 0) {
		sovle(num + 1, sum - v[num], p , m-1, g, n);
	}
	if (g != 0) {
		sovle(num + 1, sum * v[num], p , m, g-1, n);
	}	
	if (n != 0) {
		sovle(num + 1, sum / v[num], p , m, g, n-1);
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(d, 0, sizeof(d));
		v.clear();
		q.clear();
		cin >> N;
		for (int i = 0; i < 4; ++i) {
			cin >> d[i];
		}
		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sovle(1, v[0], d[0], d[1], d[2], d[3]);
		sort(q.begin(), q.end());
		int ans = q[q.size() - 1] - q[0];
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}