#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		string s;
		cin >> N;
		cin >> s;
		v.clear();
		v.resize(s.size());
		for (int i = 0; i < s.size(); i++) {			
			for (int j = i; j < s.size(); ++j) {
				v[i] += s[j];
			}
		}
		sort(v.begin(), v.end());
		cout << "#" << test_case << " " << v[N - 1] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}