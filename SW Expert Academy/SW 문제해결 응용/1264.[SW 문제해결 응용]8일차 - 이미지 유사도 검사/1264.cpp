#include<iostream>
#include <cstring>
using namespace std;
int lcs[501][501];
string str1, str2;
int main(int argc, char** argv)
{
    cout << fixed;
    cout.precision(2);
    int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
        memset(lcs, 0, sizeof(lcs));
        string temp1, tmep2;
        int N;
        cin >> N;  
		cin >> temp1;
		cin >> tmep2;
        str1 = '0' + temp1;
        str2 = '0' + tmep2;
        int len1 = str1.size();
        int len2 = str2.size();

        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (i == 0 || j == 0)
                {
                    lcs[i][j] = 0;
                    continue;
                }

                // 현재 비교하는 값이 서로 같다면, lcs는 + 1
                if (str1[i] == str2[j])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;

                // 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
                else
                {
                    if (lcs[i - 1][j] > lcs[i][j - 1])
                        lcs[i][j] = lcs[i - 1][j];
                    else
                        lcs[i][j] = lcs[i][j - 1];
                }
            }
        }
        double d = static_cast<double>(lcs[len1 - 1][len2 - 1]) / static_cast<double>(N) *100;
        cout << "#" << test_case << " " << d << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}