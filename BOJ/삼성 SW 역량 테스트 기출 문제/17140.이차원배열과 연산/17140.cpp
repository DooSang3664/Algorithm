#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 101
int arr[MAX][MAX];
int cnt[MAX]; // �� ������ ������ ���� ����
int r, c, k;

void funtion() {
	int time=0;
	int R = 3, C = 3;
	while (1) {
		if (arr[r][c] == k) {
			cout << time << endl;
			break;
		}
		if (time > 100) {
			cout << -1 << endl;
			break;
		}
		vector<int> size;
		if (R >= C) {
			//���� ����
			size.clear();
			for (int i = 1; i <= R; ++i) {
				//���ڿ� ������ ���� ����
				vector< pair<int, int>> V;
				memset(cnt, 0, sizeof(cnt));
				//���� ����
				for (int j = 1; j <= C; j++)
					cnt[arr[i][j]]++;
				//���ڽ� ���
				for (int j = 1; j < MAX; ++j) {
					if (cnt[j] == 0) continue;
					V.push_back(make_pair(cnt[j], j));
				}
				// ���� ����
				sort(V.begin(), V.end());
				//�� 0���� �ʱ�ȭ
				for (int j = 1; j <= C; ++j)
					arr[i][j] = 0;
				//���� �ֱ�
				int id = 1;
				for (int j = 0; j < V.size(); ++j) {
					arr[i][id++] = V[j].second;
					arr[i][id++] = V[j].first;
				}
				id--;
				//������ ����
				size.push_back(id);
			}
			//��ū ����� ���� ����
			sort(size.begin(), size.end());
			C = size.back();
		}
		else if (R < C) {
			size.clear();
			for (int i = 1; i <= C; ++i) {
				//���ڿ� ������ ���� ����
				vector< pair<int, int>> V;
				memset(cnt, 0, sizeof(cnt));
				//���� ����
				for (int j = 1; j <= R; j++)
					cnt[arr[j][i]]++;
				//���ڽ� ���
				for (int j = 1; j < MAX; ++j) {
					if (cnt[j] == 0) continue;
					V.push_back(make_pair(cnt[j], j));
				}
				// ���� ����
				sort(V.begin(), V.end());
				//�� 0���� �ʱ�ȭ
				for (int j = 1; j <= R; ++j)
					arr[j][i] = 0;
				int id = 1;
				for (int j = 0; j < V.size(); ++j) {
					arr[id++][i] = V[j].second;
					arr[id++][i] = V[j].first;
				}
				id--;
				size.push_back(id);
			}
			//��ū ����� ���� ����
			sort(size.begin(), size.end());
			R = size.back();
		}
		time++;
	}
}
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> arr[i][j];

	if (arr[r][c] == k) {
		cout << 0 << endl;
		return 0;
	}
	funtion();
	return 0;
}