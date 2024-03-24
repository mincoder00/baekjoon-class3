#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	map <string, int> map;
	vector<string> answer;
	cin >> n >> m;
	while (n--) {
		string str;
		cin >> str;
		map[str]++;
	}
	while (m--) {
		string str;
		cin >> str;
		map[str]++;
	}
	for (pair <string, int> p : map) {
		if (p.second == 2) {
			answer.push_back(p.first);
		}
	}
	int len = answer.size();
	cout << len << '\n';
	for(int i=0; i<len; i++){
	cout << answer[i] << '\n';
	}
}
//map<string, int >::iterator iter;
// if (iter->second == 2)
//		cout << iter->first << "\n";
// 번복자를 이용한 풀이도 가능함!!

// < -- 중요 -- >
// map 자료구조는 문자열로 배열의 위치를 정할 수 있다.
// 그리고 자동으로 사전순으로 정렬이 된다.