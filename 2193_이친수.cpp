#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long dp[2][91];
string arr;
int main() {
	fastio;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		arr.resize(100001);
		for (int i = 0; i < arr.size(); i++)arr[i] = '0';
		if (s.find("at")) {
			int temp = stoi(s.substr(3, s.size()));
			cout<< arr[temp] << endl;
		}
		else if (s.find("set")) {
			string T = s.substr(4, s.size());
			for (int i = 0; i < T.size(); i++) {
				if (T[i] == NULL) {
					int index = i;
					break;
				}
				int k = stoi(T.substr(0, i));
				int k1 = stoi(T.substr(i, T.size()));
				arr[k] = k1;
				cout << arr[k] << endl;
			}
		}
		else {
			string T = s.substr(4, s.size());
			for (int i = 0; i < T.size(); i++) {
				if (T[i] == NULL) {
					int index = i;
					break;
				}
				int k = stoi(T.substr(0, i));
				int k1 = stoi(T.substr(i, T.size()));
				arr[i].insert(k);
		}
	}
}
	int possibleNumOfWord(int A, int Z)

	{

		//기저 사례

		if (A == 0 || Z == 0)

			return 1;




		if (cache[A][Z] != -1)

			return result;



		//a를 택할 경우와 z를 택할 경우 모두 고려

		//1,000,000,000을 넘으면 조건 충족하는 단어 X

		cache[A][Z] = min(possibleNumOfWord(A - 1, Z) + possibleNumOfWord(A, Z - 1), 1000000000 + 1);

		return cache[A][Z];

	}



출처: https://jaimemin.tistory.com/572 [꾸준함]