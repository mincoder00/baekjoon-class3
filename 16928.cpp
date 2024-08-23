#include <bits/stdc++.h>
using namespace std;

int nxt[101];
int d[101]; // y에 도달하는 주사위의 횟수

int main(void) {

	// [point] 주사위에 의한 이동(+1~6)은 bfs에서 구현
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 100;i++) {
		nxt[i] = i; // 뱀이나 사다리 없는 경우
		d[i] = -1;
	}
	for (int i = 0; i < n + m; i++) {// x- >y로 좌표 이동
		int x, y;
		cin >> x >> y;
		nxt[x] = y;
	}
	/*--------------bfs 구현--------------*/
	queue<int> q;
	d[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = nxt[y]; // 좌표 이동 적용
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	cout << d[100];
}
// ref:https://guiyum.tistory.com/45