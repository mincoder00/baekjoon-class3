#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	priority_queue <int> pq;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		if (op == 0) {
			if (pq.empty())cout << '0' << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(op);
		}
	}
}



