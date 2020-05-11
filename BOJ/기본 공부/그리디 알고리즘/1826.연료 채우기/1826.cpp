//���� ä���
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int l, p, cnt=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cin >> l >> p;
	sort(v.begin(), v.end()); //�Է��� �ұ����ϰ� �� �� �ִ�.
	int id = 0;
	while (1) {
		if (p >= l) break;
		while (id < n && v[id].first <= p) {
			pq.push(v[id].second);
			id++;
		}
		if (p < l && pq.empty()) {		
			break;
		}
		p += pq.top();
		pq.pop();
		cnt++;
	}
	if (p >= l) 
		cout << cnt << endl;
	else 
		cout << -1 << endl;
	

	return 0;
}
/*
p <- �� �� �ִ� �Ÿ�.
1�� p�ȿ� �� �� �ִ� �����Ұ� �ִٸ� max-heap�� �������� �⸧�� �ִ´�.
2�� p�� l�� �����ߴ��� Ȯ��.
3�� max-heap���� �ϳ��� ���� ����. p += pq.top(); pq.pop();
4�� heap ��� �������ϸ� -1

input:
4        <-������ ����
4 4      <-������1 (Ʈ������ �Ÿ�, ������)
5 2      <-...  2
11 5     <-...  3
15 10    <-...  4
25 10    <-(l:���������Ÿ�, p:����Ʈ���ǿ���)first second

output:
3        <- �����ҿ� ���ߴ� �ּ� Ƚ��

// ���� ������ �������� ���Ұ�� -1�� ����Ѵ�.
g++ /workspace/d230/src/c1826.cpp -o /tmp/a.out && /tmp/a.out
*/
