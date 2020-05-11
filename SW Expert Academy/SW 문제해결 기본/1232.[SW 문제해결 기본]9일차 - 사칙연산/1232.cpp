#include<iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;


struct node
{
	char c;
	double data;
	int left, right;
};
vector<node> v;

int N;
double DFS(int cur) {
	//연산자라면
	// 데이터는  = DFS(L) 현재연산자 DFS(R); 
	if (v[cur].c != NULL) {
		if (v[cur].c == '+') {
			return v[cur].data = DFS(v[cur].left) + DFS(v[cur].right);
		}
		else if (v[cur].c == '-') {
			return v[cur].data = DFS(v[cur].left) - DFS(v[cur].right);
		}
		else if (v[cur].c == '*') {
			return v[cur].data = DFS(v[cur].left) * DFS(v[cur].right);
		}
		else if (v[cur].c == '/') {
			return v[cur].data = DFS(v[cur].left) / DFS(v[cur].right);
		}
	}
	else {
		return v[cur].data;
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		v.clear();
		cin >> N;
		v.resize(N + 1);
		for (int i = 0; i < N; ++i) {
			int num; string a;
			cin >> num;
			cin >> a;
			if (a == "+" || a == "-"|| a == "*" || a == "/") {
				 v[num].c = a[0];
				 cin >> v[num].left;
				 cin >> v[num].right;
				 v[num].data = 0;
			}
			else {
				v[num].data = stoi(a);
				v[num].c = NULL;
			}
		}
		cout << "#" << test_case << " ";
		cout << DFS(1);
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/