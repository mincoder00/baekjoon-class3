#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	long long res[1001]; // 나머지를 중간중간 저장할 배열 
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		res[i] = (res[i - 1] % 10007) + (res[i - 2] % 10007);
		res[i] %= 10007;
	}
	cin >> n;
	cout << res[n];

}
// 문제 조건 잘 읽자.
// 입출력 관련 사항은 특히!
//수가 굉장히 커지기 때문에 
// 마지막에 나머지 구하는 것보다 중간중간에 구해주기.