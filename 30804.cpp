#include <bits/stdc++.h>
using namespace std;
int n;
int A[200001];


int func(int p1, int p2) {
	int P[200001] = { 0 }; // 조건 충족하는 과일을 배열의 1로 변환해주는 새로운 배열
	for (int i = 0; i < n; i++) {
		P[i] = (A[i] == p1 || A[i] == p2);
	}
	int ret = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (P[i]) cnt++;
		else {
			cnt = 0;
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main(void) {
	//전역 변수 n을 메인 함수 내에서 중복 선언하면 안됨!!
	int ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= 9;i++) {
		for (int j = i + 1; j <= 9; j++) {
			ans = max(ans, func(i, j));
		}
	}
	cout << ans;
}