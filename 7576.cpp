#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int date=0;
	int m, n;	// 가로 세로
	int arr[1001][1001];
	int dx[4] = { 1, -1, 0 , 0 };
	int dy[4] = { 0, 0, 1, -1 };
	cin >> m >> n;
	queue <pair <int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i, j });
			}		
		}
	}
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 &&ㅁ nx < m && ny <n && arr[ny][nx] == 0) {
				q.push({ ny, nx });
				arr[ny][nx] = arr[y][x] + 1;
			}
		}
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			if (arr[i][j] == 0) {
				cout << -1; 
				return 0;
			}
			if (arr[i][j] > date) date = arr[i][j]; // 최댓값 구하기
		}
	}
	cout << date - 1;// 1부터 시작하므로 date -1 값이 정답/
}

//불필요한 요소들이 추가될 수록 코드가 복잡해지고 오답 확률이 높아진다.
// arr[ny][nx] == 0을 했으므로 -1의 경유는 고려하지 않아도 처리된다.
// 이 문제의 가장 중요한 실마리는 이전 큐 값 +1을 해서 거리를 측정한다는 개념