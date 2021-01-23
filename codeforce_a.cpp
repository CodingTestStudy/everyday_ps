#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	int test_case; cin >> test_case;
	while (test_case--) {
		int n; string s; cin >> n;
		cin >> s;
		string ans = "1";
		int prev = (s[0] - '0') + 1;
		for (int i = 1; i < s.size(); i++) {
			int T = s[i] - '0';
			if (T + 1 == prev) {
				ans += '0';
				prev = T;
			}
			else {
				ans += '1';
				prev = T + 1;
			}

		}
		cout << ans << "\n";
		
	}
}