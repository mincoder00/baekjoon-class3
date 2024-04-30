#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, least;
    cin >> n;
    int* dp = new int[n + 1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        least = 50001;
        for (int j = 1; j * j <= i; j++) {
            int res = i - j * j;
            least = min(least, dp[res]);
        }
        dp[i] = least + 1;
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}

//arr[5] = 1 + arr[1]; // 2의 제곱 + 1
//arr[6] = 1 + arr[2]; //2의 제곱 + 2
//arr[40] = > res = 39, 36, 31, 24, 15 ,4 => 1+ dp[4] =2
//1 4 9 16 25 36 
// 1+ dp[res]꼴에서 dp[res]를 최적화하는 방식으로 최소 개수 탐색