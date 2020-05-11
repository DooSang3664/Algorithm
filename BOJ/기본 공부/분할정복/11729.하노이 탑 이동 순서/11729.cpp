#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int n;

void hanoe(int num, int from,int by,int to) {
	if (num == 1) {
		v.push_back({ from,to });
	}
	else {
		hanoe(num - 1, from, to, by);
		v.push_back({ from,to });
		hanoe(num - 1, by, from, to);
	}
}

int main() {
	cin >> n;
	hanoe(n,1,2,3);
	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}