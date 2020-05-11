#include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000+1

struct Tree{
	int left;
	int right;
};

Tree tree[MAX];
int V, E, x, y;
int parent = 0;
int BFS(int start) {
	queue<int> q;
	q.push(start); 
	int cnt = 0;
	while (!q.empty()) {
		int cx = q.front();
		q.pop();		
		if (cx == x || cx == y) {
			cnt++;
		}
		if (cnt == 2) {
			break;
		}
		int nx;
		if (tree[cx].left != 0) {
			nx = tree[cx].left;
			q.push(nx);
		}
		if (tree[cx].right != 0) {
			nx = tree[cx].right;
			q.push(nx);
		}
	}
	return cnt;
}

void DFS(int root) {
	int L=0, R=0;
	if (tree[root].left != 0) {
		L = BFS(tree[root].left);
	}
	if (tree[root].right != 0) {
		R = BFS(tree[root].right);
	}

	if (L == 1 && R == 1) {
		parent = root;
		return;
	}
	else if (L == 2) {
		DFS(tree[root].left);
	}
	else if (R == 2) {
		DFS(tree[root].right);
	}
	else {
		return;
	}	
}
int sum(int root) {
	int L = 0, R = 0;
	if (tree[root].left != 0) {
		L = sum(tree[root].left);
	}
	if (tree[root].right != 0) {
		R = sum(tree[root].right);		
	}
	return 1 + L + R;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> V >> E >> x >> y;
		for (int i = 0; i < E; ++i) {
			int a, b;
			cin >> a >> b;
			if (tree[a].left == 0) {
				tree[a].left = b;

			}
			else {
				tree[a].right = b;
			}
		}
		DFS(1);
		cout << "#" << test_case << " " << parent << " "<< sum(parent) <<endl;
		for (int i = 1; i <= V; ++i) {
			tree[i].left = 0;
			tree[i].right = 0;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}