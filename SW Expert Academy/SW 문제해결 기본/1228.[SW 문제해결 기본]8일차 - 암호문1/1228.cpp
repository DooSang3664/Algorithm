#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define NMAX 21
//int arr[NMAX];
vector<int> arr;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		arr.clear();
		int N,C;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		cin >> C;
		for (int i = 0; i < C; ++i) {
			char c= ' ';
			int x= 0, y= 0;
			cin >> c >> x >> y;
			for (int j = 0; j < y; ++j) {
				int temp = 0;
				cin >> temp;
				if (x + j <= N) {
					arr.insert(arr.begin() + x + j, temp);
				}
			}
			
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
11
449047 855428 425117 532416 358612 929816 313459 311433 472478 589139 568205
7
I 1 5 400905 139831 966064 336948 119288 I 8 6 436704 702451 762737 557561 810021 771706 I 3 8 389953 706628 552108 238749 661021 498160 493414 377808 I 13 4 237017 301569 243869 252994 I 3 4 408347 618608 822798 370982 I 8 2 424216 356268 I 4 10 512816 992679 693002 835918 768525 949227 628969 521945 839380 479976
19
566753 244528 233616 328235 268163 292641 646305 944392 643695 385788 444752 939244 637877 325283 779273 712343 953523 846222 204307
5
I 0 4 600576 565945 486128 594841 I 0 1 150706 I 8 8 556294 697547 932203 845517 116062 300371 621038 358830 I 10 8 747039 701738 805438 502654 476665 919177 367272 859931 I 15 3 844423 973297 658751

*/