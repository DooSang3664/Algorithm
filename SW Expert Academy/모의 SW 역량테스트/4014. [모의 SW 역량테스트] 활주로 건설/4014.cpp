#include<iostream>

using namespace std;

#define MAX 21
int map[MAX][MAX];
int N, X;
int out = 0;
void solve() {
	int cnt = 0;
	int temp = 0;

	for (int i = 0; i < N; ++i) {
		// ���ΰ˻�
		cnt = 0;
		for (int j = 0; j < N - 1; ++j) {
			cnt++;
			temp = map[i][j] - map[i][j + 1];
			//������
			if (temp == 1) {
				bool flag = false;
				for (int x = 0; x < X; x++) {
					if (j + 1 + x >= N || map[i][j + 1] != map[i][j + 1 + x]) {
						flag = true;
						break;
					}
				}
				if (flag == true) {
					break;
				}
				j += (X - 1);
				cnt = 0;
			}
			//������
			else if (temp == -1) {
				if (cnt >= X)
					cnt = 0;
				else
					break;
			}
			// �� ����
			else if (abs(temp) > 1) {
				break;
			}
			if (j == N - 2) {
				out++;
			}

		}
		// ���ΰ˻�
		cnt = 0;
		for (int j = 0; j < N-1; ++j) {
			cnt++;
			temp = map[j][i] - map[j+1][i];
			//������
			if (temp == 1) {
				bool flag = false;
				for (int x = 0; x < X; x++) {
					if (j + 1 + x >= N || map[j+1][i] != map[j + 1 + x][i]) {
						flag = true;
						break;
					}
				}
				if (flag == true) {
					break;
				}
				j += (X - 1);
				cnt = 0;
			}
			//������
			else if (temp == -1) {
				if (cnt >= X)
					cnt = 0;
				else
					break;
			}
			// �� ����
			else if (abs(temp) > 1) {
				break;
			}
			if (j == N - 2) {
				out++;
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
		out = 0;
		cin >> N >> X;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
			}
		}
		solve();
		cout << "#" << test_case << " " << out << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}