#include<iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
deque<int> dq;
int arr[50][100];
void check() {
	bool ok = false;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			if (arr[i][j] == 1) {
				int cnt = 56;
				while (cnt--) {
					dq.push_front(arr[i][j--]);				
					ok = true;
				}
				if (ok) {
					return;
				}
			}
		}
	}
}

int ch(int num) {
	if (num == 26) { return 0; }
	else if (num == 50) { return 1; }
	else if (num == 38) { return 2; }
	else if (num == 122) { return 3; }
	else if (num == 70) { return 4; }
	else if (num == 98) { return 5; }
	else if (num == 94) { return 6; }
	else if (num == 118) { return 7; }
	else if (num == 110) { return 8; }
	else if (num == 22) { return 9; }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			string temp;
			cin >> temp;
			for (int j = 0; j < temp.size(); ++j) {
				arr[i][j] = temp[j] -'0';
			}
		}
		check();
		int arr[8] = { 0, };
		for (int i = 0; i < 8; ++i) {
			int sum = 0;
			for (int j = 7; j > 0; --j) {
				int temp = dq.front();
				dq.pop_front();
				if (temp == 1) {
					temp = pow(2, j);
					sum += temp;					
				}
			}
			arr[i] = ch(sum);
		}
		int temp1 = (arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5]+arr[7];
		if (temp1 % 10 == 0) {
			int sum1=0;
			for (int i = 0; i < 8; ++i) {
				sum1 += arr[i];
			}
			cout << "#" << test_case << " " << sum1<<endl;
		}
		else {
			cout << "#" << test_case << " " << 0 << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}