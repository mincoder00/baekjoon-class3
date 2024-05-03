#include <bits/stdc++.h>
using namespace std;
int n, m, v;
int arr[1001][1001];
bool visit_b[1001];
bool visit_d[1001];

void dfs(int v) {
	visit_d[v] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[v][i] == 1 && visit_d[i] == false) {
			cout << i <<' ';
			dfs(i);
		}
	}
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	cout << v<<' ';
	visit_b[v] = true;
	while (!q.empty()) {
		v = q.front();
		for (int i = 1; i <= n;i++) {
			if (arr[v][i] == 1 && visit_b[i] == false) {
				q.push(i);
				visit_b[i] = true;
				cout << i << ' ';
			}
		}
		q.pop();
	}
}


int main(void) {
	int x, y;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		arr[y][x] = 1;
		arr[x][y] = 1;
	}

	cout << v << ' ';
	dfs(v);
	cout << '\n';
	bfs(v);
}
//bfs는 큐를 이용해서 구현
//dfs는 재귀함수를 이용해서 구현
//틀렸었던 부분은 bool배열을 한 가지로 사용해서 ambiguous에러
//초기화를 해봤으나 여전히 컴파일에러 -> 그냥 bool 배열 두 개 ㅁ하자