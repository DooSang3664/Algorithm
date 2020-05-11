#include <iostream>
#include <algorithm>
#define MAX 100000+1
using namespace std;
int n;
int arr[MAX];
int DP[MAX];
int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	int m = arr[0];
	for (int i = 1; i < n; ++i) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
		m = max(m, DP[i]);
	}
	cout << m << endl;
	return 0;
}