#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, int>m;
int main() {
	string s; cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j <= s.size()-i; j++) {
			string temp = s.substr(j, i);
			m[temp]++;
		}
	}
	cout << m.size();
}