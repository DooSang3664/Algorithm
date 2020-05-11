#include <iostream>
using namespace std;
int N;
int DParr[1001];
int DP(int n) {
	if (n == 1) { return 1; }
	else if (n == 2) { return 2; }
	if (DParr[n] != 0) { return DParr[n]; }
	else {
		DParr[n] = (DP(n - 1) + DP(n - 2))%10007;
		return DParr[n];
	}
}
int main() {
	cin >> N;
	cout << DP(N) << endl;

}