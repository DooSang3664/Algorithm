#include<iostream>

using namespace std;
int mony[4];
int plen[13];
int out = 0;
void DFS(int month,int sum) {
	if (month > 12) {
		if (out > sum) {
			out = sum;
		}
		return;
	}
	if (plen[month] == 0) {
		DFS(month + 1, sum);
	}
	else {
		DFS(month + 1, plen[month] * mony[0] + sum);
		DFS(month + 1,  mony[1] + sum);
		DFS(month + 3, mony[2] + sum);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; ++i) {
			cin >> mony[i];
		}
		for (int i = 1; i < 13; ++i) {
			cin >> plen[i];
		}
		out = mony[3];
		DFS(1,0);
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}