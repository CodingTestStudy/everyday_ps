#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v;
bool flag = false;
bool okay = false;
bool check[1001];
int main() {
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		v.resize(n*2);
		for (int i = 0; i < 2 * n; i++)cin >> v[i];
		sort(v.begin(), v.end(),greater<int>());
		int now =0;
		for (int i = 1; i < 2 * n; i++) {
			if (okay)break;
			flag = false;
		memset(check, false, sizeof(check));
		vector<pair<int, int>>temp;
		temp.push_back({ v[0],v[i] });
		check[0] = true;
		check[i] = true;
		for (int j = 1; j < 2 * n; j++) {
			auto [a, b] = temp.back();
			int MAX = max(a, b);
			if (check[j])continue;
			check[j] = true;
			int cur = -1;
			for (int k = j + 1; k < 2 * n; k++) {
				if (v[j] + v[k] == MAX) {
					cur = v[k];
					check[k] = true;
					break;
				}
			}
			if (cur == -1) {
				flag = true;
				break;
			}
			temp.push_back({ v[j],cur });
			}
		if (temp.size() == n) {
			for (auto T : temp) {
				cout<<T<<
			}
			okay = true;
			break;
		}
		}
			 

		}
}