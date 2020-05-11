#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<int> map;
int main(int argc, char** argv)
{
	int test_case;
	int T=2;

	int N;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < 100; ++i) {
			int temp;
			cin >> temp;
			map.push_back(temp);
		}
		for (int i = 0; i < N; ++i) {
			sort(map.begin(),map.end());
			map[0]++;
			map[99]--;
		}
		sort(map.begin(), map.end());
		cout << "#" << test_case << " " << map[99] - map[0] << endl;
		map.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}