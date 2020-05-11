#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
struct Magnetic
{
	int x;
	int m;
};
Magnetic M[10];
int N;


int main(int argc, char** argv)
{
	cout << fixed;
	cout.precision(10);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> M[i].x;
		}
		for (int i = 0; i < N; ++i) {
			cin >> M[i].m;
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < N-1; ++i) {
			double L = M[i].x;
			double R = M[i+1].x;
			double S=0;
			double out = 0;			
			while (R - L > pow(10,-12) ) {
				S = (L + R) / 2;
				double F = 0;
				for (int j = 0; j < i + 1; ++j) {
					F += M[j].m/((S-M[j].x)* (S - M[j].x));
				}
				for (int j = i+1; j < N; ++j) {
					F -= M[j].m / ((S - M[j].x) * (S - M[j].x));
				}
				if (F > 0) {
					L = S;
				}
				else {
					R = S;		
					out = S;
				}
			}			
			cout << out << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}