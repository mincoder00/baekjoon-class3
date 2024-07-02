#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
//최대공약수

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
//최소공배수
int main(void) {
	int m, n, x, y, t;
	cin >> t;
	while (t--) {
		int result=-1;
		int res_y=0;
		cin >> m >> n >> x >> y;
		int maxi = lcm(m, n);
		for (int i = x;i <= maxi;i+=m) { // x=2이라면 2부터 시작해서 <2,5> (m=10,n=6)
			res_y = (i % n); //2 ,12, 22 ,32, 중에서 6로 나눈 나머지가 5인거?
			if (res_y == 0) {
				res_y = n;

			}
			if (res_y == y) {
				result = i;
				break;
			}
		}
		cout << result << '\n';
	}
	
}