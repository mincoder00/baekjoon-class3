#include <bits/stdc++.h>
using namespace std;
int arr[26][26];
bool check[26][26];
int cnt = 1;
vector <int> numOfHouse;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int n;

void bfs(int i, int j) {
	queue<pair <int, int>> q;
	q.push({ i,j });
	check[i][j] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (arr[ny][nx] && !check[ny][nx] && ny >= 1 && ny <= n && nx >= 1 && nx <= n) {
				q.push({ ny,nx });
				check[ny][nx] = 1;
				cnt++;
			}
		}
	}
}

void dfs(int i, int j) {
	check[i][j] = true;
	pair<int, int>cur = { i,j };
	for (int i = 0;i < 4;i++) {
		int ny = cur.first + dy[i];
		int nx = cur.second + dx[i];
		if (arr[ny][nx] && !check[ny][nx] && ny >= 1 && ny <= n && nx >= 1 && nx <= n) {
			check[ny][nx] = 1;
			cnt++;
			dfs(ny, nx);
		}
	}
}

int main(void) {

	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			char a;
			cin >> a;
			arr[i][j] = a - '0';
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (arr[i][j] && !check[i][j]) {
				bfs(i, j); //dfsµµ ¹«°ü
				numOfHouse.push_back(cnt);
				cnt = 1;
			}
		}
	}
	cout << numOfHouse.size() << '\n';
	sort(numOfHouse.begin(), numOfHouse.end());
	for (int i = 0;i < numOfHouse.size();i++) {
		cout << numOfHouse[i] << '\n';
	}
}