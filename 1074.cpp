#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int n, r, c;

void dc(int y, int x, int size) {//시작 지점, 행.열 size
	if ((y == r) && (x == c)) {
		cout<< ans;
		return;
	}
	else if ((r<y+size) && (c<x+size)&&(y<=r)&&(x<=c)) {//범위 내 적중  p.s) 재귀 함수 호출 제어
		dc(y, x, size / 2);
		dc(y, x+size / 2, size / 2);	
		dc(y + size / 2, x, size / 2);
		dc(y + size / 2, x + size / 2, size / 2);
	}
	else {//범위 바꾸자!
		ans += size*size;
	}

}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> r >> c;
	dc(0, 0, pow(2, n));
	return 0;
}


//divide conquer 구상할 때는 엣지케이스나 지엽적인 부분을 고려하기보다는
//먼저 큰 그림 짜기
//원하는 시나리오가 안 나오면 조건문의 조건 설정을 검토해보기
//메모리 초과 문제는 주로 재귀 호출이 너무 깊어지면 메모리 초과