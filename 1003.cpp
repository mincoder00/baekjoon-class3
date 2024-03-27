#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int DP[41][2];
    DP[0][0] = 1;
    DP[0][1] = 0;
    DP[1][0] = 0;
    DP[1][1] = 1;
    for (int i = 2; i <= 40;i++) {
        DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
        DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;ㅁ
        cout << DP[n][0] << ' ' << DP[n][1] << '\n';
    }
}
//재귀함수 ->시간초과
//DP
// [N]       [0출력횟수]           [1출력횟수]
//0      1                  0
//1      0                  1
//2      1                  1
//3      1                  2  
//4      2                  3  

//N이 40이 최대로 크지 않으니까 한번에 배열 다 만들고 값 호출하기