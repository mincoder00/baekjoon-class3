#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, t;

	cin >> t;
	while (t--) {
		string op, str;
		bool reverse = false, error = false; // bool 활용하기
		deque<int> dq;
		cin >> op;
		cin >> n;
		cin >> str;
		string s = ""; //빈 문자열 선언
		for (int i = 0; i < str.length();i++) {
			if (isdigit(str[i])) {//0부터 9 사이의 숫자인지
				s += str[i];
			}	
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";

				}
			}
		}
		for (auto o : op) {
			if (o == 'R') {
				if (reverse) reverse = false;
				else reverse = true;
			}
			else {
				if (dq.empty()) {
					cout << "error" << '\n';
					error = true;
					break;
				}
				if (reverse) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}
		if (!error) {
			cout << '[';
		}
		if (reverse && !dq.empty()) {
			for (auto o = dq.rbegin(); o < dq.rend(); o++) {
				if (o == dq.rend() - 1) cout << *o;
				else cout << *o << ',';
			}
		}		
		if (!reverse && !dq.empty()) {
			for (auto o = dq.begin(); o < dq.end(); o++) {
				if (o == dq.end() - 1) cout << *o ;
				else cout << *o << ',';
			}
		}
		if (!error) {
			cout << ']'<<'\n';
		}

	}



}