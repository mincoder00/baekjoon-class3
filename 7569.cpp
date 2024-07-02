#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int tomato[101][101][101]; // 면, 행, 열 순서
int dist[101][101][101]; // 거리 저장
int day = 0;// 정답
queue < pair<pair<int, int>, int>> q; // {{면, 행}, 열} 
int dx[6] = { 1,-1,0, 0,0,0, };
int dy[6] = { 0,0,-1, 1,0,0, };
int dh[6] = { 0,0,0,0,1,-1 };

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n >> h;
	for (int i = 0;i < h;i++) {
		for (int j = 0; j < n;j++) {
			for (int k = 0;k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) dist[i][j][k] = -1; // dist가 -1인 경우 (익지 x)관심대상
				if (tomato[i][j][k] == 1) q.push({ {i,j},k });
			}
		}	
	}
	// bfs 구현
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0;i < 6;i++) {
			int nh = cur.first.first+dh[i];
			int ny = cur.first.second+dy[i];
			int nx = cur.second+dx[i];
			if (nh < 0 || ny < 0 || nx < 0 || nh >= h || nx >= m || ny >= n) continue;
			if (dist[nh][ny][nx] >= 0) continue; // dist가 0일때도 pass해도됨(토마토 안들어있는경우)
			else {
				dist[nh][ny][nx] = dist[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ {nh,ny}, nx });
			}
		}
	}
	for (int i = 0;i < h;i++) {
		for (int j = 0; j < n;j++) {
			for (int k = 0;k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << "-1"; //""큰따옴표
					return 0;
				}
				day = max(day, dist[i][j][k]);
			}
		}
	}
	cout << day;
	//ref:https://m.blog.naver.com/fbfbf1/222023071187



}