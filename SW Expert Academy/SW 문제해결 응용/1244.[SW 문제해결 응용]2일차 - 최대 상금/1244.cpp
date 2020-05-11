#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string S;
int N;
vector<int> v;
int arr[1000000][11];
int m_mony = 0;

void swep(int x, int y) {
	char temp = S[x];
	S[x] = S[y];
	S[y] = temp;
}

void DFS(int cnt) {
	if (cnt >= N) {
		int temp = stoi(S);
		if (m_mony < temp) {
			m_mony = temp;
		}
		return;
	}
	if (arr[stoi(S)][cnt]) return;
	arr[stoi(S)][cnt] = 1;
	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < S.size(); ++j) {
			if (i != j) {
				swep(i, j);
				DFS(cnt + 1);
				swep(i, j);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		m_mony = 0;
		v.clear();
		cin >> S >> N;
		DFS(0);
		cout << "#" << test_case << " " << m_mony << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}