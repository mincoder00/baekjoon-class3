#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;
	map <string, string> m;
	cin >> N >> M;
	while (N--) {
		string name, pw;
		cin >> name;
		cin >> pw;
		m[name] = pw;
	}
	while (M--) {
		string name, pw;
		cin >> name;
		pw = m[name];
		cout << pw << '\n';
	}
}