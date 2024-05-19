#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector <string> v;
	int t, m;
	cin >> t;
	while (t--) {
		int L = 100;
		v.clear();
		cin >> m;
		int temp = m;
		while (temp--) {
			string mbti;
			cin >> mbti;
			v.push_back(mbti);
		}
		if (m > 32) {
			cout << 0 << '\n';
			continue;;
		}
		for (int i = 0; i < m - 2;i++) {
			int cnt = 0;
			for (int j = i + 1; j < m - 1;j++) {
				for (int k = j + 1;k < m;k++) {
					for (int l = 0;l < 4;l++) {
						if (v[i][l] != v[j][l]) cnt++;
						if (v[i][l] != v[k][l]) cnt++;
						if (v[j][l] != v[k][l]) cnt++;
					}
				}
			}
			if (cnt < L) L = cnt;
		}
		cout << L << '\n';
	}

}

