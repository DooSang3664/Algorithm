#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long  A, B, V;
	cin >> A >> B >> V;
	long long  L = 0, R = V / (A - B) + 1;
	long long  M,out = 1000000000;
	while (L <= R) {
		M = (L + R) / 2;
		if (V <= M * (A - B) + A) {
			out = min(out, M + 1);
			R = M - 1;
		}
		else
			L = M + 1;
	}
	cout << out << endl;
	return 0;
}