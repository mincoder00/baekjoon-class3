#include <bits/stdc++.h>
using namespace std;
bool visited[100001];

void bfs(int n, int k) {
	queue<pair <int,int>> q;// 현 지점 + 걸린 시간 저장하는 pair q
	q.push({ n, 0 });
	visited[n] = true; // 방문여부 확인
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k) {
			cout << cnt;
			break;
		}
		if (x * 2 >= 0 && x * 2 <= 100000 && !visited[x * 2]) {
			q.push({ x * 2, cnt + 1 });
			visited[x * 2] = true;
		}
		if (x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1]) {
			q.push({ x -1, cnt + 1 });
			visited[x - 1] = true;
		}
		if (x + 1>=0 && x+ 1 <= 100000 && !visited[x + 1]) {
			q.push({ x + 1, cnt + 1 });
			visited[x + 1] = true;
		}
	}
}

int main() {
	int n, k;
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	bfs(n, k);
	return 0;
}
//bfs + dp의 메모이제이션 기법을 떠올려서 pair <x, cnt>으로 구현