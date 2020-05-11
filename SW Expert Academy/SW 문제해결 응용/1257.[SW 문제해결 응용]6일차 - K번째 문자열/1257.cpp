#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		string s;
		cin >> N;
		cin >> s;
		v.clear();
		for (int i = 0; i < s.size(); i++) {
			string temp = "";
			temp += s[i];
			v.push_back(temp);
			for (int j = i+1; j < s.size();j++) {
				temp += s[j];
				v.push_back(temp);
				
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		if (v.size() <= N - 1) {
			cout << "#" << test_case << " " << "none" << endl;
		}
		else {
			cout << "#" << test_case << " " << v[N - 1] << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}