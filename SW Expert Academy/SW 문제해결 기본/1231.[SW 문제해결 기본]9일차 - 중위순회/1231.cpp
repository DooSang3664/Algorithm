#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


struct node
{
	char c;
	int left, right;
};
vector<node> v;

int N;
void DFS(int cur) {
	if(v[cur].left != -1){
		DFS(v[cur].left);
	}
	cout << v[cur].c;
	if (v[cur].right != -1) {
		DFS(v[cur].right);
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
		v.resize(N+1);	
		for (int i = 0; i < N; ++i) {
			int num;
			cin >> num;
			cin >> v[num].c;
			if (num * 2 <= N) {
				cin >> v[num].left;
			}
			else {
				v[num].left = -1;
			}
			if ((num * 2 )+ 1 <= N) {
				cin >> v[num].right;
			}
			else {
				v[num].right = -1;
			}
		}
		cout << "#" << test_case << " ";
		DFS(1);
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*

*/