#include <bits/stdc++.h>
using namespace std;
#define fast cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
int main(void) {
	fast;
	vector <int> vec;
	int m,x;
	string op;
	cin >> m;
	while (m--) {
		cin >> op;
		sort(vec.begin(), vec.end());
		if (op == "add") {
			cin >> x;
			if (binary_search(vec.begin(), vec.end(), x)) continue;
			else vec.push_back(x);

		}
		if (op == "remove") {
			cin >> x;
			if (!binary_search(vec.begin(), vec.end(), x)) continue;
			else {
				vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
			}

		}
		if (op == "check") {
			cin >> x;
			cout << binary_search(vec.begin(), vec.end(), x)<< '\n';
		}
		if (op == "toggle") {
			cin >> x;
			if (binary_search(vec.begin(), vec.end(), x)) {
				vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
			}
			else vec.push_back(x);
		}
		if (op == "all") {
			vec.clear();
			for (int i = 1;i <= 20;i++) vec.push_back(i);
		}
		if (op == "empty") {
			vec.clear();
		}
	}

}