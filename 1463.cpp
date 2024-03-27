#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int* arr = new int[n + 1];
	arr[1] = 0; arr[2] = 1; arr[3] = 1;
	if (n <= 3) {
		cout << arr[n];
		return 0;
	}
	for (int i = 4; i <= n; i++) {
		if (i % 6 == 0) {	// case1 : 6의 배수
			arr[i] = min(arr[i / 2], arr[i / 3]) + 1;

		}
		else if (i % 3 == 0) { // case2 : 6의 배수가 아닌 3의 배수
			arr[i] = min(arr[i / 3] + 1, arr[i - 1] + 1);
		}
		else if (i % 2 == 0) {  // case3 : 6의 배수가 아닌 2의 배수
			arr[i] = min(arr[i / 2] + 1, arr[i-1]+1);
		}
		else {	//case4 : 2의 배수도 아닌 3의 배수
			arr[i] = arr[i - 1]+1;
		}
	}
	cout << arr[n]; return 0;
	delete[]  arr;
}

// X   (과정)	N
//1				0
//2				1
//3				1
//4	 4->2->1	2
//5	 5->4->2	2
//6	 6->2->1	2
//7	7->6->2->1 	3
//8	8->4->2->1 	3
//8	8->7->6->2->1 	4
//9	9->3->1 	2
//10 10->9->3->1 	3
//11 11->10		4
//12 12->4->2->1		3
//13 		4
//14 		4
//15 -> 5-> 4->2->1
//18 ->6->2->1
//24 ->8->4->2->1
//24 ->12->3->1

