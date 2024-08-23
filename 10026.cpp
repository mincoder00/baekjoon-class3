#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char grid[101][101];
string input;
bool visited[101][101];
//상하좌우
int dx[4] = { 0, 0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = true;
	for (int i = 0; i < 4;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (grid[ny][nx] == grid[y][x] && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*입력 받기*/
	cin >> n;
	for (int y = 0; y < n;y++) {
		cin >> input;
		for (int x = 0;x < n;x++) {
			grid[y][x] = input[x];
		}
	}
	/*적록색약 아닌 사람*/
	for (int y = 0; y < n;y++) {
		for (int x = 0;x < n;x++) {
			if (!visited[y][x]) {
				dfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt<<'\n';

	/*적록색약인 사람*/
	cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int y = 0; y < n;y++) {
		for (int x = 0;x < n;x++) {
			if (grid[y][x] == 'G') grid[y][x] = 'R';
		}
	}
	for (int y = 0; y < n;y++) {
		for (int x = 0;x < n;x++) {
			if (!visited[y][x]) {
				dfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}




//ref:https://balhyohongsam.tistory.com/entry/%EB%B0%B1%EC%A4%80-10026%EB%B2%88-%EC%A0%81%EB%A1%9D%EC%83%89%EC%95%BD-CC

ㅁ//dfs를 돌 땐 
// 다음 이동하는 좌표와 현재 좌표의 색이 같고 
// 방문한 적이 없을 때만 재귀 함수를 실행

//적록색약의 경우 grid 수정 후 dfs 카운트