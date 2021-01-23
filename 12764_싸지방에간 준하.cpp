#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q1;
int n;
int arr[100001];
vector<pair<int, int>>v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, ed; cin >> st >> ed;
		v.push_back({ st,ed });
	}
	sort(v.begin(), v.end());
	q.push({ v[0].second,1 });
	int cur = v[0].first;
	arr[1]++;
	int idx = 1;
	int ans = 1;
	int cnt = 1;
	while (idx<n) {
		int now = q.top().first;
		int num = q.top().second;
		if (q1.empty()) {
			if (now > cur) {
				q.push({ v[idx++].second,++cnt });
				arr[cnt]++;
			}
			else {
				while (!q.empty()&&q.top().first < cur) {
					auto [a, b] = q.top();
					q.pop();
					q1.push({ b,a });
				}
				auto [a, b] = q1.top();
				q1.pop();
				q.push({ v[idx++].second,a });
				arr[a]++;
			}
		}
		else {
			auto [a, b] = q1.top();
			q1.pop();
			q.push({ v[idx++].second,a });
			arr[a]++;
		}
		int size = q.size();
		ans = max(size, ans);
		if (idx == n)break;
		cur = v[idx].first;
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++)cout << arr[i] << " ";
}