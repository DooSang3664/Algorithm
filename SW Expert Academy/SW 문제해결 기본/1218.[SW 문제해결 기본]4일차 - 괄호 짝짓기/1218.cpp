#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[4] = { 0,0,0,0 };
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		int N;
		string s;
		cin >> N;
		cin >> s;
		for (int i = 0; i < N; ++i) {
			if (s[i] == '(') {
				arr[0]++;
			}
			else if (s[i] == '[') {
				arr[1]++;
			}
			else if (s[i] == '{') {
				arr[2]++;
			}
			else if (s[i] == '<') {
				arr[3]++;
			}

			if (s[i] == ')') {
				arr[0]--;
			}
			else if (s[i] == ']') {
				arr[1]--;
			}
			else if (s[i] == '}') {
				arr[2]--;
			}
			else if (s[i] == '>') {
				arr[3]--;
			}
		}
		bool ok = true;
		for (int i = 0; i < 4; ++i) {
			if (arr[i] != 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "#" << test_case << " " << 1 << endl;
		}
		else {
			cout << "#" << test_case << " " << 0 << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}