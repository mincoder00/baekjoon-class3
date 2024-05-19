#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
bool check[101];
int n, ans=0;

void dfs(int i, int j) {
	for (int t = 0; t < n;t++) {
		if (!check[t]&&arr[i][t]==1) {
			check[t] = true;
			if (t == j) {
				ans = 1;
				return;
			}
			dfs(t, j);
		}
	}
}

int main(void) {

	cin >> n;	
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n; j++) {
			memset(check, false, sizeof(check));
			ans = 0;ㅁ
			dfs(i, j);
			cout << ans<<' ';
		}
		cout << '\n';
	}
}
//visit이름으로 arr 생성 시 컴파일 에러 가능성
//<bits/stdc++.h> 헤더에서 가져온 visit 함수와 
// 전역 배열로 선언한 visit 배열 간에 모호성 발생

// dfs(start, end) 형식으로 start = end일 때까지 실행
// 방향이 있는 그래프 형식으로 입력 인접행렬이 대칭행렬이 아님에 주의