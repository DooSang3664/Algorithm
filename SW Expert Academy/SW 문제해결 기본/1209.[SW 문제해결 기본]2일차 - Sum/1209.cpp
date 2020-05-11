#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
using namespace std;

int arr[100][100];
int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> arr[i][j];
			}
		}
		//행
		int sum=0;
		int sum1 = 0;
		for (int i = 0; i < 100; ++i) {
			int a = 0;
			int b = 0;
			for (int j = 0; j < 100; ++j) {
				a += arr[i][j];
				b += arr[j][i];
			}
			sum = max(sum, a);
			sum1 = max(sum1, b);
		}
		int sum2 = 0;
		int sum3 = 0;
		for (int i = 0; i < 100; ++i) {
			sum2 += arr[i][i];
			sum3 += arr[100 - (1 + i)][i];
		}
		cout << "#" << N << " " << max({sum,sum1,sum2,sum3}) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
1
4 4 3 2 1
2 2 1 6 5
3 5 4 6 7
4 2 5 9 7
8 1 9 5 6
*/
