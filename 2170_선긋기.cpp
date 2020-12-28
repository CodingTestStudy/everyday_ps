#include <bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;

int main() {
	int n; cin >> n; f;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	int st = -INF;
	int ed = -INF;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		auto [a,b] = v[i];
		if (ed < a) {
			sum += ed - st;
			st = a;
			ed = b;
		}
		else {
			ed = max(ed, b);
		}
		if (i == n - 1)sum += ed - st;
	}
	cout << sum;
}

