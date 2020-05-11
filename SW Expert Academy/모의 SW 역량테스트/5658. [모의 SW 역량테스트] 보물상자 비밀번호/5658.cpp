#include<iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,k;
deque<char>q;
vector<string>v;
int num;
void solve() {
	for (int i = 0; i < 4; ++i) {
		string s = "";
		for (int j = i* num; j < i * num + num; ++j) {
			s += q[j];
		}
		v.push_back(s);
	}
}
bool cmp(string a, string b) {
	return a > b;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{		
		cin >> n >> k;
		num = n / 4; // �Ѻ��� ����
		for (int i = 0; i < n; ++i) {
			char a;
			cin >> a;
			q.push_back(a);
		}
		//�̾Ƴ���
		solve();
		for (int i = 0; i < num-1; ++i) {
			int temp = q.back();
			q.pop_back();
			q.push_front(temp);
			solve();
		}
		//�ߺ�����
		sort(v.begin(), v.end(),cmp);
		v.erase(unique(v.begin(), v.end()),v.end());
		
		//����
		char a[20];
		for (int i = 0; i < num; ++i) {
			a[i] = v[k-1][i];
		}
		int nDec = (int)strtol(a, NULL, 16);
		
		cout << "#" << test_case << " "<< nDec << endl;
		
		//�ʱ�ȭ
		v.clear();
		while (!q.empty()) {
			q.pop_back();
		}
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}