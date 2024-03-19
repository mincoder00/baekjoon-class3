#include <bits/stdc++.h>
using namespace std;
#define fast cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
int main(void) {
	fast;
	map <string, int> pokemon; // 도감 hash map
	vector<string> name; // name 벡터
	int n, m;
	string temp; 
	cin >> n >> m;
	vector<string> result; // result 벡터
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		name.push_back(temp);
		pokemon.insert(make_pair(temp, i));
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp[0] >= 65 && temp[0] <= 90) {// 포켓몬 이름일 때
			result.push_back(to_string(pokemon[temp]));
		}
		else result.push_back(name[stoi(temp)-1]);  // 번호일 때
	}
	for (int i = 0; i < m; i++) cout << result[i]<<'\n';
}
//벡터는 입력받을 때 동적으로 크기가 조정되기 때문에
//0인덱스부터 시작 안하면 OUT		OF RANGE 오류 
// vector pair 자료형으로 시도했지만 시간초과
// hash map 을 사용하자!
// 아스키 코드로 A = 65, Z=90
//해시 맵에 key값에는 포켓몬 이름 value 값에는 도감 번호를 저장
// name배열을 만들어 포켓몬 이름을 도감 번호대로 저장