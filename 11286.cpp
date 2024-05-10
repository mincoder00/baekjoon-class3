#include <bits/stdc++.h>
using namespace std;

int main(void) {
	priority_queue < pair<int, int>, vector <pair <int, int>>, greater <pair<int, int>>> pq;
	int t;
	cin >> t;
	while (t--) {
		int op;
		cin >> op;
		if (op == 0) {
			if (pq.empty()) {
				cout << '0' << '\n';
			}
			else {
				if (pq.top().second < 0) {
					cout << -pq.top().first << '\n';
				}
				else cout << pq.top().first << '\n';
				pq.pop();
			}
		}
		else {
			if (op > 0) {
				pq.push({ op, 1 });
			}
			else {
				pq.push({ -op, -1 });
			}
		}
	}

}

//우선순위 큐에서 절댓값이 낮은게 우선순위 , 같으면 음수인 값을 선택
//음수 flag 레지스터 개념으로 pair형으로 음수면 -1 부여, -붙여서 절댓값 비교
// 출력할 때 second가 -1(음수라는 뜻) 이면 -first로 출력
// 우선순위 큐는 pair 비교할 때 첫번째거가 우선순위 같으면 두번째거로 비교
