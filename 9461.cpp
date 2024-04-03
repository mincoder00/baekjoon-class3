#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long int arr[101];
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	int t, n;
	cin >> t ;
	while (t--) {
		cin >> n;
		cout << arr[n]<<'\n';
	}

}

//1, 1, 1, 2, 2, 3, 4, '5', '7', '9', '12', '16', '21', '28'
// 파도반 수열의 항은 매우 큰 값이 될 수 있으므로  long long 타입을 사용
// arr[i] = arr[i-2] + arr[i-3]도 가능한 솔루션