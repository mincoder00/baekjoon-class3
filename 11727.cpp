#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	int res[1001] = {0};
	res[0] = 1;
	res[1] = 3;
	for (int i = 2; i < 1000; i++) {
		res[i] = res[i - 1]%10007 + 2*(res[i - 2]%10007);
		res[i] %= 10007;
	}
	cin >> n;
	cout << res[n-1];

}