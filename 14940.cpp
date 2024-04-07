#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	int dist[1001][1001]; //초기화 주의 사항: 영이 아닌 값으로 모두 초기화 -> 반복문
	int arr[1001][1001];
	bool visited[1001][1001] = { false };
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	queue <pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i, j }); // 목표지점을 출발 지점으로 역발상 !
				dist[i][j] = 0; // 출발 지점이니까 거리가 0이겠지?
				visited[i][j] = true;
			}
		}
	}
	// bfs 구현
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];
			if (visited[ny][nx]) continue;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (arr[ny][nx] == 0) continue; // 이 조건 설정해주어야함!!
			else {
				dist[ny][nx] = dist[cur.first][cur.second] + 1;
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cout << 0<<' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}


//초기화할 때 주의할 점 !!!!
// int arr[3] = { -1 };은 첫 번째 요소만 - 1로 초기화하고
// 나머지 요소는 0으로 초기화된다....