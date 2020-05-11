#include<iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;



int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		deque<int> left, right;
		int N;
		cin >> N;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			right.push_back(s[i]-'0');
		}
		for (int i = 0; i <N; ++i) {
			//같을경우
			if (left.size() == 0) {
				left.push_back(right.front());
				right.pop_front();
			}
			else if (right.size() == 0) {
				break;
			}
			if (left.back() == right.front()) {
				left.pop_back();
				right.pop_front();
			}
			//다를경우
			else {
				left.push_back(right.front());
				right.pop_front();
			}
		}

		cout << "#" << test_case << " ";
		while (!left.empty()) {
			cout << left.front();
			left.pop_front();
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/