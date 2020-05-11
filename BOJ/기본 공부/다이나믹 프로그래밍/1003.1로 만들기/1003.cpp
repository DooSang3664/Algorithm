#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000000+1

using namespace std;

int x;
int memo[MAX + 1] = { 0, 0, 1, 1 };

int dp(int x) {
    switch (x) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 1;
    }
    if (memo[x] != 0) {
        return memo[x];
    }
    if (x % 6 == 0) {
        return memo[x] = min({ dp(x / 3), dp(x / 2), dp(x - 1) }) + 1;
    }
    else if (x % 3 == 0) {
        return memo[x] = min({ dp(x / 3), dp(x - 1) }) + 1;
    }
    else if (x % 2 == 0) {
        return memo[x] = min({ dp(x / 2), dp(x - 1) }) + 1;
    }
    else {
        return memo[x] = dp(x - 1) + 1;
    }
}

int main() {
    cin >> x;

    cout << dp(x) << endl;

    return 0;
}