#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[101];
int op[4];
vector<int> v;
void DFS(int s, int m, int l, int g, int sum,int cnt) {
	if (cnt == N) {
		v.push_back(sum);
		return;
	}
	if(s > 0)
		DFS(s - 1, m, l, g, sum+arr[cnt], cnt + 1);
	if (m > 0)
		DFS(s , m-1, l, g, sum - arr[cnt], cnt + 1);
	if (l > 0)
		DFS(s , m, l-1, g, sum * arr[cnt], cnt + 1);
	if (g > 0)
		DFS(s , m, l, g-1, sum / arr[cnt], cnt + 1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}
	DFS(op[0], op[1], op[2], op[3], arr[0],1);
	sort(v.begin(), v.end());
	
	cout << v.back() << endl;
	cout << v.front() << endl;
	return 0;
}
