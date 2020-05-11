#include<iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;


struct node
{
	char c;
};
vector<char> v;


bool ok = true;


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T =10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ok = true;
		int N;
		v.clear();
		cin >> N;
		v.resize(N + 1);
		for (int i = 1; i <= N; ++i) {
			int num;
			char c;
			cin >> num >> c;
			if (N % 2 == 0 && N / 2 > i || N % 2 == 1 && N / 2 >= i) {
				int temp1, temp2;
				cin >> temp1 >> temp2;
			}
			else if (N % 2 == 0 && N / 2 == i) {
				int temp3;
				cin >> temp3;
			}
			v[num] = c;		
		}
		for (int i = 1; i <= N; ++i) {
			if (N / 2 >= i) {
				if (v[i] == '+' || v[i] == '-' || v[i] == '*' || v[i] == '/') {}
				else {
					ok = false;
					break;
				}
			}
			else if (N / 2 < i) {
				if (v[i] == '+' || v[i] == '-' || v[i] == '*' || v[i] == '/') {
					ok = false;
					break;
				}
				else {};
			}
		}
		cout << "#" << test_case << " ";
		if (ok) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/