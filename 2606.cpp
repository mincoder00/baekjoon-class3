	#include <bits/stdc++.h>
	using namespace std;
	int n, m;
	int arr[101][101]; // 그래프를 표현할 인접행렬

	int bfs(int v) {
		int cnt = 0;
		bool visit[101] = { false };	// 방문 여부
		queue<int> q; // 큐를 통해 bfs 탐색
		q.push(v);
		visit[v] = true;
		while (!q.empty()) {
			v = q.front();
			for (int i = 1; i <= n; i++) {
				if (arr[v][i] == 1 && visit[i] == false) {
					q.push(i);
					visit[i] = true;
					cnt++;
				}
			}
			q.pop();
		}
		return cnt;
	}

	int main(void) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1; // 인접행렬 구성
			arr[y][x] = 1; // symetric으로 만들어줘야함
		}
		cout << bfs(1);
	}