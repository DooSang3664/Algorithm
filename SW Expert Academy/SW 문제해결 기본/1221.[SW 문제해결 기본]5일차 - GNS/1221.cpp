#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string arr[10] = { "ZRO" ,"ONE" ,"TWO" ,"THR","FOR","FIV","SIX","SVN","EGT","NIN" };
int cnt[10];
int main(int argc, char** argv)
{
	int test_case;
	int T ;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(cnt, 0, sizeof(cnt));
		int N;
		string t;
		cin >> t;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < 10; ++j) {
				if (arr[j] == s) {
					cnt[j]++;
				}
			}
		}
		cout << "#" << test_case << endl;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < cnt[i]; ++j) {
				cout << arr[i] << " ";
			}			
		}
		cout << endl;		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}