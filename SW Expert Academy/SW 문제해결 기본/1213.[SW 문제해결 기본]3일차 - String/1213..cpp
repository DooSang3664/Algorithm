#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		string st, ed;
		cin >> st;
		cin >> ed;
		int cnt = 0;
		for (int i = 0; i < ed.size()-1; ++i) {
			if (ed[i] == st[0]) {
				bool ok = true;
				for (int j = 1; j < st.size(); ++j) {				
					if (ed[i + j] != st[j])
						ok = false;
				}
				if (ok) {
					cnt++;
				}
			}

		}
		cout << "#" << N << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
