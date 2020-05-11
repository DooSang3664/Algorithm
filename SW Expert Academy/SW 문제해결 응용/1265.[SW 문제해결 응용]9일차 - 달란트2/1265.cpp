#include<iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, E;
		cin >> N >> E;
		int m = N / E;
		int s = N % E;
		long long ans = pow(m+1, s) * pow(m, E-s);
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}