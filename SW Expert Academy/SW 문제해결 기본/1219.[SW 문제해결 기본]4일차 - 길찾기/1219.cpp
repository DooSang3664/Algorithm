#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map1[100];
int map2[100];
int ok = 0;
void DFS(int cur) {
	if (map1[cur] == 99 || map2[cur] == 99) {
		ok = 1;
		return;
	}
	else {
		if (map1[cur] != -1) {
			DFS(map1[cur]); 
		}
		if (map2[cur] != -1) { 
			DFS(map2[cur]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 100; ++i) {
			map1[i] = -1;
			map2[i] = -1;
		}
		ok = 0;
		int N;
		int size;
		cin >> N >> size;
		for (int i = 0; i < size; ++i) {
			int a, b;
			cin >> a >> b;
			if (map1[a] == -1) {
				map1[a] = b;
			}
			else {
				map2[a] = b;
			}
		}
		DFS(0);
		cout << "#" << N << " " << ok << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}