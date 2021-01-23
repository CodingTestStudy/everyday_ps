#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<pair<int, int>>v;
int main() {
	int test; cin >> test;
	while (test--) {
		int num,cnt=1; cin >> num;
		v.clear();
		for (int i = 0; i < num; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
			sort(v.begin(), v.end());
		}
		int prev = v[0].second;
		for (int i = 1; i < num; i++) {
			if (v[i].second < prev) {
				cnt++;
				prev = v[i].second;
			}
		}
		cout << cnt << endl;
	}
}