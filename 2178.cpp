#include <bits/stdc++.h>
using namespace std;
queue <pair <int, int>> q;
int n, m;
int arr[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited [101][101];
int dist[101][101];

void bfs(int y, int x) {
	dist[y][x] = 1;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		pair <int, int> cur = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			pair <int, int> next = { cur.first + dy[i], cur.second + dx[i] };
			if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)continue;
			if (visited[next.first][next.second] == true)continue;
			if (arr[next.first][next.second] == 0) continue;
			dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
			q.push(next);
			visited[next.first][next.second] = true;
		}
	}
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i <n;i++) {
		string row; 
		cin >> row;
		for (int j = 0; j < m;j++) {
			arr[i][j] = row[j]-'0';
		}
	}
	bfs(0, 0);
	cout << dist[n - 1][m - 1];

}

