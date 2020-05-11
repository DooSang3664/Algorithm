//연료 채우기
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
	sort(v.begin(), v.end()); //입력이 불균형하게 올 수 있다.
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
p <- 갈 수 있는 거리.
1번 p안에 갈 수 있는 주유소가 있다면 max-heap에 주유소의 기름량 넣는다.
2번 p로 l에 도착했는지 확인.
3번 max-heap에서 하나를 꺼내 주유. p += pq.top(); pq.pop();
4번 heap 비고 도착못하면 -1

input:
4        <-주유소 개수
4 4      <-주유소1 (트럭과의 거리, 주유량)
5 2      <-...  2
11 5     <-...  3
15 10    <-...  4
25 10    <-(l:최종도착거리, p:원래트럭의연료)first second

output:
3        <- 주유소에 멈추는 최소 횟수

// 만약 마을에 도착하지 못할경우 -1을 출력한다.
g++ /workspace/d230/src/c1826.cpp -o /tmp/a.out && /tmp/a.out
*/
