#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y;
bool arr[51][51];
bool check[51][51] = { 0 };
int x_step[4] = { 1, -1, 0, 0 };// 열 증가
int y_step[4] = {0, -0, -1, 1}; // 행 증감

bool dfs(int a, int b) {
	if (check[a][b]) return false;
	check[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int next_x = b + x_step[i]; //열
		int next_y = a + y_step[i]; //행
		if (next_x < m && next_y < n && next_x >= 0 && next_y >= 0 && arr[next_y][next_x]) {
			dfs(next_y, next_x);
		}
	}
	return true;
}

int main(void) {
	cin >> t;
	while (t--) {
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		cin >> m >> n >> k;
		while (k--) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !check[i][j]) {
					if (dfs(i, j)) cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}