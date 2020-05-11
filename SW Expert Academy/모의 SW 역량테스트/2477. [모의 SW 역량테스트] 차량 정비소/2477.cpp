#include<iostream>
#include <vector>

struct point
{
	int num;
	int time;
};
struct men
{
	int time;
	int j1;
	int j2;
	bool start;
};

using namespace std;

point J1[10];
point J2[10];
vector<men> Men;
int N, M, K, A, B;

void solve() {
	int time = 0;
	while (1) {
		/*for (int i = 0; i < Men.size(); ++i) {
			if (Men[i].time == time) {
				Men[i].start = true;
			}
		}
		for (int i = 0; i < Men.size(); ++i) {
			if (Men[i].start == true) {
				for (int i = 0; i < N; ++i) {
					if(J1[i]== 0)
				}
			}
		}*/
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K >> A >> B;
		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			J1[i].time = temp;
		}
		for (int i = 0; i < M; ++i) {
			int temp;
			cin >> temp;
			J2[i].time = temp;
		}
		for (int i = 0; i < K; ++i) {
			int temp;
			cin >> temp;
			Men.push_back({ temp,NULL,NULL,false });
		}
		solve();
	}
	return 0;
}