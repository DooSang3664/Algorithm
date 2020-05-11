#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
#define INF 100000
int N;
vector<int> v[MAX];
int map[MAX][MAX];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		//�� �ʱ�ȭ
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 0) {
					map[i][j] = INF;
				}
				if (i == j) {
					map[i][j] = 0;
				}			
			}
		}
		//�÷��̵�
		for (int k = 1; k <= N; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= N; ++j) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
		int m = INF;
		for (int i = 1; i <= N; ++i) {
			int temp = 0;
			for (int j = 1; j <= N; ++j) {
				if(i != j)
					temp += map[i][j];
			}
			if (m > temp) {
				m = temp;
			}			
		}
		cout << "#" << test_case << " " << m << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}