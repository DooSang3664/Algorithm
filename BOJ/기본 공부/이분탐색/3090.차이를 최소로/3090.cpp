#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100000+1
using namespace std;
int N, T;
int arr[MAX];
int copy_arr[MAX];
int out[MAX];
bool check(int m) {
	for (int i = 0; i < N; ++i) {
		copy_arr[i] = arr[i];
	}
	int cnt = 0;
	for (int i = 0; i < N-1; ++i) {
		if (copy_arr[i + 1] - copy_arr[i] > m) {
			cnt += copy_arr[i + 1] - (copy_arr[i] + m); //1만큼 감소시키므로 
			copy_arr[i + 1] = copy_arr[i] + m;
		}
	}
	for (int i = N-1; i > 0; --i) {
		if (copy_arr[i -1] - copy_arr[i] > m) {
			cnt += copy_arr[i - 1] - (copy_arr[i] + m);
			copy_arr[i - 1] = copy_arr[i] + m;
		}
	}
	if (cnt <= T) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		//pq.push(arr[i]);
	}
	int L = 0, R = 1e9;
	while (L <= R) {
		int M = (L + R) / 2;
		if (check(M)) {
			for (int i = 0; i < N; ++i) {
				out[i] = copy_arr[i];
			}
			R = M - 1;
		}
		else {
			L = M + 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << out[i] << ' ';
	}
	return 0;
}