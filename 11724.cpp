#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1001][1001] = { 0 };
bool checked[1001];
queue <int > q;
int cnt = 0;


void bfs(int v) {
	q.push(v);
	checked[v] = true;
	while (!q.empty()) {
		v = q.front();
		for (int i = 1; i <= n; i++) {
			if (arr[v][i] == 1 && checked[i] == false) {
				checked[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
}


int main(void) {
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (checked[i] == false) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
}

//bfs풀이로 구현.
ㅁ