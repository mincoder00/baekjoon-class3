#include <bits/stdc++.h>
using namespace std;
int main(void) {
	int dp[12];
	int t, n;
	cin >> t;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 11;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}


}
//규칙성 발견!
//1			1
// 2		2
// 3		4
// 4		7
// 5		13
// 6		24
// 7		44
