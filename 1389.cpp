#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101][101];
queue <int> q;
int dist[101];
bool check[101];

void bfs(int v) {
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 1;i <= n;i++) {
			if (arr[v][i] && !check[i]) {
				q.push(i);
				check[i] = true;
				dist[i] = dist[v] + 1;
			}
		}
	}
}


int main(void) {
	int sum = 0;
	int numOfPerson=0;
	int L = 500001;
	cin >> n >> m;
	while (m--) {
		int y, x;
		cin >> y >> x;
		arr[y][x] = 1;
		arr[x][y] = 1;
	}
	for (int i = 1;i <= n;i++) {
		bfs(i);
		for (int p = 1;p <= n;p++) sum += dist[p];
		if (sum < L) {
			numOfPerson = i;
			L = sum;
		}
		sum = 0;
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
	}
	cout << numOfPerson;

}
//너비 우선 탐색
//인접행렬로 구현하지만, 사람이므로 일차원 bool
//최단거리를 구하기 위해서는 bfs 
//dist배열을 통해서 거리 저장