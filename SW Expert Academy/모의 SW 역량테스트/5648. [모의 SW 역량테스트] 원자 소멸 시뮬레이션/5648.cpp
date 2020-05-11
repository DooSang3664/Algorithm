#include<iostream>
#include <queue>
using namespace std;
struct point {
	int x;
	int y;
	int dir;
	int num;
};

vector<point>v;
int map[4001][4001];
int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int out = 0;

void solve() {
	while (!v.empty()) {
		int size = v.size();
		for (int i = 0; i < size; ++i) {
			map[v[i].y][v[i].x] = 0;
			int dir = v[i].dir;
			int nx = v[i].x + dx[dir];
			int ny = v[i].y + dy[dir];
			if (nx < 0 || ny < 0 || nx > 4000 || ny > 4000) {
				v[i].num = 0;
				continue;
			}
			v[i].x = nx;
			v[i].y = ny;
			map[ny][nx] += v[i].num;
		}
		for (int i = 0; i < size; ++i) {
			if (v[i].num == 0) continue;
			int cx = v[i].x;
			int cy = v[i].y;
			if (map[cy][cx] != v[i].num) {
				out += map[cy][cx];
				map[cy][cx] = 0;
				v[i].num = 0;
			}
		}
		vector<point>temp;
		/*for (int i = 0; i < v.size(); ++i) {
			temp.push_back(v[i]);
		}*/
		temp.assign(v.begin(), v.end()); // 벡터 복사 <- 포문보다 빠른듯?
		v.clear();
		for (int i = 0; i < temp.size(); ++i) {
			if (temp[i].num != 0) {
				v.push_back(temp[i]);
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		out = 0;
		cin >> N; 
		for (int i = 0; i < N; ++i) {
			int x, y;
			int dir, num;
			cin >> x >> y >> dir >> num;
			x += 1000; // 배열에 담을 수 있게하기위해
			y += 1000;
			x *= 2; // 원자간의 거리를 2배로해서 0.5에서 안만나게
			y *= 2;
			v.push_back({ x,y,dir,num });
		}
		solve();
		cout << "#"<<test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
#include<iostream>
#include <queue>
using namespace std;
struct point {
	float x;
	float y;
	int dir;
	int num;
};
struct check {
	float x;
	float y;
	int dir;
	int num;
	bool check;
};
queue<point> q;
vector<check>v;
int N;
float dx[4] = { 0,0,-0.5,0.5 };
float dy[4] = { 0.5,-0.5,0,0 };
int out = 0;
void solve() {
	while (1) {
		int size = q.size();
		if (size == 0) {
			return;
		}
		else {
			//한칸씩 이동
			for (int i = 0; i < size; ++i) {
				float cx = q.front().x;
				float cy = q.front().y;
				int c_num = q.front().num;
				int dir = q.front().dir;
				q.pop();
				float nx = cx + dx[dir];
				float ny = cy + dy[dir];

				if (nx < -1000 || ny < -1000 || ny > 1000 || nx > 1000) {
					continue;
				}
				v.push_back({ nx,ny,dir,c_num,false });
			}
			//겹치는 부분 삭제
			vector<int>temp;
			if (v.size() != 0) {
				for (int i = 0; i < v.size(); ++i) {
					for (int j = 0; j < v.size(); ++j) {
						if (i != j && v[j].check == false) {
							if (v[i].x == v[j].x && v[i].y == v[j].y) {
								temp.push_back(j);
							}
						}
					}
					if (temp.size() != 0) {
						for (int j = 0; j < temp.size(); ++j) {
							out += v[temp[j]].num;
							v[temp[j]].check = true;
						}
						out += v[i].num;
						v[i].check = true;
						temp.clear();
					}
				}


				for (int i = 0; i < v.size(); ++i) {
					if (v[i].check == false)
						q.push({ v[i].x,v[i].y,v[i].dir,v[i].num });
				}
				v.clear();
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		out = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			float x, y;
			int dir, num;
			cin >> x >> y >> dir >> num;
			q.push({ x,y,dir,num });
		}
		solve();
		cout << "#"<<test_case << " " << out << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/