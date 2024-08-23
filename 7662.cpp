#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, less<int>> maxHeap; // 최댓값 삭제를 위한 최대힙
priority_queue <int, vector<int>, greater<int>> minHeap; // 최솟값 삭제를 위한 최소힙
map <int, int>cnt; // 각 원소의 잔여 개수를 저장하는 map

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, k, n;
	char op;

	cin >> t;
	while (t--) {	
		/*초기화*/
		cnt.clear();
		while (!maxHeap.empty()) maxHeap.pop();
		while (!minHeap.empty()) minHeap.pop();
		cin >> k;

		/*연산 수행*/
		while (k--) {
			cin >> op >> n;
			if (op == 'I') {//삽입
				cnt[n]++;
				maxHeap.push(n);
				minHeap.push(n);
			}
			if (op == 'D') {//삭제
				if (n == 1&& !maxHeap.empty()) {//최댓값 삭제
					cnt[maxHeap.top()]--;
					maxHeap.pop();
				}
				else if (n == -1 &&!minHeap.empty()) {//최솟값 삭제
					cnt[minHeap.top()]--;
					minHeap.pop();
				}
				//한쪽 큐에서의 삭제 사항을 다른 큐에서도 반영
				while (!maxHeap.empty() && cnt[maxHeap.top()] == 0) maxHeap.pop();
				while (!minHeap.empty() && cnt[minHeap.top()] == 0) minHeap.pop();

			}
		}
		/*정답 출력*/
		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY\n";
		}
		else cout << maxHeap.top() << ' ' << minHeap.top()<<'\n';
	}
}