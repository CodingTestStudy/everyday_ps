#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v;
int main() {
	int n; cin >> n;
	while (n--) {
		bool ok = false;
		int a, b; cin >> a >> b;
		v.resize(a);
		for (int i = 0; i < a; i++) {
			cin >> v[i];
			if (v[i] > b)ok = true;
		}
		sort(v.begin(), v.end());
		if (ok) {
			if (v[0] + v[1] <= b)cout << "YES";
			else cout << "NO";
		}
		else cout << "YES";
		cout << "\n";
	}
}