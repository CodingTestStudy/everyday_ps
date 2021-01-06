#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
vector<ll>v;
ll MAX = 1e15;
ll dp = 0;
int main() {
	int n, m; cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end(),greater<int>());
	ll high = MAX;
	ll low = 1;
	ll mid = (high + low) / 2;
	while (low <= high) {
		mid = (low + high) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] <= mid)break;
			sum += v[i] - mid;
		}
		if (sum < m) {
			high = mid - 1;
		}
		else {
			dp = max(dp, mid);
			low = mid + 1;
		}
	}
	cout << dp;
}