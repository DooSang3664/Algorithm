#include<iostream>

using namespace std;
int map[14][21];
int N, M, K;
bool check[14];
bool ABcheck[14];
bool flag;

/*void solve(int cnt) {
	if (cnt == 0) {
		//그냥 검사
		bool bflag = false;
		for (int i = 0; i < M; ++i) {
			int cnt = 1;
			int cur = map[i][0];
			for (int j = 1; j < N; ++j) {
				if (map[i][j] == cur) {
					cnt++;
				}
				else {
					cnt = 1;
					cur = map[i][j];
				}
				if (cnt == K) {
					bcnt++;
					break;
				}
			}
			if(cnt < K)
			if(bcnt == M)
		}
	}
	else {
		//시약 넣고 검사
	}
}*/
void DFS(int cnt,int pos,int max) {
	if (pos > N)
		return;
	if (cnt == max) {
		for (int i = 0; i < N; ++i) {
			cout << check[i] << " ";
		}

		//solve(cnt);
		return;
	}
	DFS(cnt, pos + 1, max);
	check[pos] = true;
	DFS(cnt+1, pos + 1, max);
	check[pos] = false;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		flag = false;
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> map[i][j];
			}
		}
		DFS(0,0, 2);
		/*for (int i = 0; i <= K; ++i) {
			if (flag == false) {
				DFS(0,0,i);
			}
		}*/
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}