#include <iostream>
#include <vector>

using namespace std;
int num, n;

int funtion(int num,int n) {
	if (n == 1) {
		return num;
	}
	else {
		return funtion(num, n / 2) * funtion(num, (n / 2) + (n % 2));
	}
}

int main() {
	cin >> num >> n;
	cout << funtion(num,n);
	return 0;
}