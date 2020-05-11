#include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
int N;
int map[10][10];
struct M {
	int x;
	int y;
	bool check;
};
vector<pair<pair<int, int>, int>> door;
vector<M> men;
int outdoor[11];
int exitnum = 0;
int output = INF;
deque<int> door0;
deque<int> door1;
int dist(int x, int y, int dx, int dy) {
	return abs(x - dx) + abs(y - dy);
}
void solve() {
	int time = 0;
	while (1) {
		time++;
		for (int i = 0; i < men.size(); ++i) {
			if (outdoor[i] == 0) {
				if (dist(men[i].x, men[i].y, door[0].first.first, door[0].first.second) == time) {
					if (men[i].check == false) {
						if (door0.size() >= 3) {
							door0.push_back(door[0].second);
							men[i].check = true;
						}
						else {
							door0.push_back(door[0].second + 1);
							men[i].check = true;
						}
					}
				}
			}
			else if (outdoor[i] == 1) {
				if (dist(men[i].x, men[i].y, door[1].first.first, door[1].first.second) == time) {
					if (men[i].check == false) {
						if (door1.size() >= 3) {
							door1.push_back(door[1].second);
							men[i].check = true;
						}
						else {
							door1.push_back(door[1].second + 1);
							men[i].check = true;
						}
					}
				}
			}
		}
		//int temp0[3] = { 0, };
		//int temp1[3] = { 0, };
		queue<int> temp0;
		queue<int>temp1;
		for (int i = 0; i < 3; ++i) {
			if (door0.size() > 0) {
				int temp = door0.front();
				door0.pop_front();
				temp--;
				if (temp < 0) {
					exitnum++;
					i--; continue;
				}
				temp0.push(temp);
			}
		}
		for (int i = 0; i < 3; ++i) {
			if (door1.size() > 0) {
				int temp = door1.front();
				door1.pop_front();
				temp--;
				if (temp < 0) {
					exitnum++;
					i--;
					continue;
				}
				temp1.push(temp);
			}
		}
		for (int i = 0; i < 3; i++) {
			if (temp0.size() > 0) {
				door0.push_front(temp0.front());
				temp0.pop();
			}
			if (temp1.size() > 0) {
				door1.push_front(temp1.front());
				temp1.pop();
			}
		}

		if (exitnum == men.size()) {
			if (output > time) {
				output = time;
			}
			cout << " " << time;
			cout << endl;
			break;
		}

	}
}
void DFS(int cnt, int pos) {
	if (cnt == men.size()) {
		exitnum = 0;
		for (int i = 0; i < men.size(); ++i) {
			men[i].check = false;
		}

		for (int i = 0; i < men.size(); ++i)
			cout << outdoor[i] << " ";
		cout << endl;
		solve();
		return;
	}
	for (int i = pos; i < men.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			outdoor[i] = j;
			DFS(cnt + 1, i + 1);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		output = INF;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					men.push_back({ i,j,false });
				}
				else if (map[i][j] != 0 && map[i][j] != 1) {
					door.push_back({ {i,j},map[i][j] });
				}
			}
		}
		DFS(0, 0);
		door.clear();
		men.clear();
		cout << "#" << test_case << " " << output << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}