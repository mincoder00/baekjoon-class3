#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m;
	long long start, end, mid, sum = 0;
	int max = -1;
	cin >> n >> m;
	long long* arr = new long long[n + 1];
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	start=0;
	end = arr[n - 1];
	while (start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) continue;
			else sum += arr[i] - mid;
		}
		if (sum >= m) {
			start = mid + 1;
			if (mid > max) max = mid;
		}
		else end = mid - 1;
	}
	cout << max;
}
//4 42 40 26 46
//정렬하면
//4 26 40 42 46
//mid = 23
//만약에 mi= 23일때 sum>=m이라면 23보다 작은 mid 에 대해서는 전혀 고려할 필요가 없다
//('적어도 m'을 충족했기 때문에 값을 더 줄일 필요가 없음)
// 23보다 오른쪽에 해당하는 즉 23~46까지 사이에서 고려
// (24+46)/2  = 35 
//sum>=m인 경우의 mid값들을 max에 담으면서 마지막에 max에 담긴 값이 정답

