#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
using namespace std;

int arr[101];
int main(int argc, char** argv)
{
	int test_case;
	int T ;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		for (int i = 1; i <= 100; ++i) {
			arr[i] = 0;
		}
		cin >> N;
		for (int i = 0; i < 1000; ++i) {
			int temp;
			cin >> temp;
			arr[temp]++;
		}
		int m=0;
		for (int i = 1; i <= 100; ++i) {
			m = max(m, arr[i]);
		}
		for (int i = 100; i >= 1; --i) {
			if (arr[i] == m) {
				cout << "#" << N << " " << i << endl;
				break;
			}
		}
		arr[3];
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
} 
