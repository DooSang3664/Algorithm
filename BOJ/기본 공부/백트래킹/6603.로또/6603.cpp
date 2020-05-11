#include <iostream>
using namespace std;

int N;
int arr[13];
int check[6];

void backt(int arr_num, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << check[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = arr_num; i < N; i++){
		check[cnt] = arr[i];
		backt(i + 1, cnt + 1);
	}
}
int main() {
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];

		backt(0,0);
		cout << endl;
	}
	return 0;
}