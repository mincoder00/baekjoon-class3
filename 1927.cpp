#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	priority_queue<int, vector <int>, greater <int>> minHeap;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (minHeap.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << minHeap.top()<<'\n';
				minHeap.pop();
			}
		}
		else  {
			minHeap.push(x);
		}
	}
}

//최소 힙 기반 pq 선언 방법
//	priority_queue<int, vector <int>, greater <int>ㅁ> minHeap;