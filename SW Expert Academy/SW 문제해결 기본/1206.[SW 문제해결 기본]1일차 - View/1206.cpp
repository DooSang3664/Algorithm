#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int N;
int map[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	while (t--) {
		int N;
		cin >> N;
		int cnt = 0;
		int a = 1;
		for (int i = 0; i < N; ++i) {
			cin >> map[i];
		}	
		for (int i = 2; i < N - 2; ++i) {		
			//¿ÞÂÊ
			int num = map[i] - max({ map[i - 2],map[i - 1] ,map[i + 1] ,map[i + 2] });
			if (num > 0) cnt += num;
		}
		cout << "#" << a << " "<<cnt << endl;
	}
	return 0;
}
