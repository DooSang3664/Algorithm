#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

vector<int> arr;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		arr.clear();
		int N, C;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		cin >> C;
		for (int i = 0; i < C; ++i) {
			char c = ' ';
			int x = 0, y = 0;
			cin >> c >> x >> y;
			if (c == 'I') {
				for (int j = 0; j < y; ++j) {
					int temp = 0;
					cin >> temp;
					if (x + j <= N) {
						arr.insert(arr.begin() + x + j, temp);
					}
				}
			}
			else if (c == 'D') {
				arr.erase(arr.begin() + x, arr.begin() + x + y);
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/