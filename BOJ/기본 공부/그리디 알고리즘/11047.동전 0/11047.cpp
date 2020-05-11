#include <iostream>

using namespace std;
int arr[11];
int main() {
	int N, K;
	int sum =0,cnt=0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = N-1; i >= 0; --i) {
		if (K == 0)
			break;
		if (arr[i] > K)
			continue;
		cnt += K / arr[i];
		K %= arr[i];
	}	
	cout << cnt << endl;
}