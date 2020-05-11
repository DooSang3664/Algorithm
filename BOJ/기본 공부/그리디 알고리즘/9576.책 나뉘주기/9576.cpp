#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define max 1000+1

bool check[max];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		memset(check, false, sizeof(check));
		cin >> N >> M;		
		vector<pair<int, int>> v;
		for (int j = 0; j < M; ++j) {
			int a, b;
			cin >> a >> b;
			v.push_back({ b,a });
		}
		// 사이간격에 따라 솔트
		sort(v.begin(), v.end());

		int count = 0;
		for (int j = 0; j < M; ++j) {
			for (int h = v[j].second; h <= v[j].first; h++) {
				if (!check[h]) {
					check[h] = true;
					count++;
					break;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}
/*
			1	2	3	4	5	6	7	8	9
			xo		xo
							
						
	(1, 2) (3, 7) (3, 3) (5, 6)
	1 2   33  56  37
*/
/* 최대 학생 수 출력.
*핵심: 책의 범위가 작은 학생부터 우선하여 시작한다.
 ㄴ 학생에게 준 책은 체크하는 배열을 준비해둘 것.
input:
1
2 3
1 2
1 2
1 2

output:
2
*/
