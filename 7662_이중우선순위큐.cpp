#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		int n; cin >> n;
		multiset<int> MS;
		while (n--) {
			char c; int i; cin >> c >> i;
			if (c == 'I') MS.insert(i);
			else if (c == 'D') {
				if (i == 1 && !MS.empty()) MS.erase(--MS.end());
				else if (i == -1 && !MS.empty()) MS.erase(MS.begin());
			}
		}
		if (MS.empty()) cout << "EMPTY\n";
		else cout << *(--MS.end()) << ' ' << *MS.begin() << '\n';
	}
}
