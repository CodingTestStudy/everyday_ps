#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s,ans;
bool flag;
char temp;
map<char, int>m;
int main() {
	cin >> s;
	int cnt = 0, index = 0;
	for (int i = 0; i < s.size(); i++)
		m[s[i]]++;
	if (s.size() % 2 == 0) {
		for (auto T : m) {
			if (T.second % 2)flag = true;
			for (int i = 0; i < T.second / 2; i++)ans += T.first;
		}
		string tt = ans;
		reverse(tt.begin(), tt.end());
		ans += tt;
	}
	else {
		for (auto T : m) {
			if (T.second % 2) {
				cnt++;
				temp = T.first;
				for (int i = 0; i < T.second / 2; i++)ans += T.first;
			}
			else for (int i = 0; i < T.second / 2; i++)ans += T.first;
		}
		if (cnt != 1)flag = true;
		string tt = ans;
		reverse(tt.begin(), tt.end());
		ans += temp+tt ;
	}
	if (flag)cout << "I'm Sorry Hansoo";
	else cout << ans;
}