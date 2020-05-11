#include <iostream>
using namespace std;
int N, S;
int arr[20+1];
int num = 0;

void funtion(int cnt, int sum) {
	sum += arr[cnt];
	if (cnt >= N)
		return;
	if (sum == S) { 
		num++;
	}
	funtion(cnt + 1, sum - arr[cnt]);
	funtion(cnt + 1, sum);
}



int main() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	funtion(0,0);
	cout << num << endl;
	return 0;
}