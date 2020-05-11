#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
deque<int> dq;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		for (int i = 0; i < 8; ++i) {
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		int num = 1;
		while (1) {
			if (dq.back() == 0) {
				break;
			}
			int temp = dq.front();
			dq.pop_front();
			if (temp - num < 0) {
				dq.push_back(0);
			}
			else {
				dq.push_back(temp - num);
			}
			if (num == 5) {
				num = 1;
			}
			else {
				num++;
			}
			
		}
		cout << "#" << N << " " ;
		while(!dq.empty()) {
			cout << dq.front() << " ";
			dq.pop_front();
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}