#include<iostream>
#include <cstdio>
using namespace std;
int a, b;
int funtion(int b) {
	if (b == 1) {
		return a;
	}
	return a* funtion(b-1);
}
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;

		cin >> N;
		cin >> a >> b;
		cout << "#" << N << " " << funtion(b) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}