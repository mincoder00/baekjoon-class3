#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string S;
	int cnt = 0;
	int k = 0;
	int n, m;
	cin >> n;
	cin >> m;
	cin >> S;
	for (int i = 0; i < m;i++)
	{
		if (S[i] == 'O') continue;
		else {
			while (S[i + 1] == 'O' && S[i + 2] == 'I') {
				k++;
				i += 2;
				if (k == n) {
					k--;
					cnt++;
				}
			}
			k = 0;
		}
	}
	cout << cnt;
}
//substr(7, 5)는 7번 인덱스부터 시작하여 5개
//하지만 서브스트링 만드는 것은 부분점수 
//while문 O(n)의 방법 고민
//'IOI'의 개수로 해결!!