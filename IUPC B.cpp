#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long dp[201][201];
map<int, int >M;
vector<int>v;
int main() {
	fastio;
	int n, m; cin >> n >> m;
	while (n--) {
		int num; cin >> num;
		v.push_back(num);
		M[num]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int now; cin >> now;
		if (!M[now])cout << "-1"<<"\n";
		else {
			cout << lower_bound(v.begin(), v.end(), now) - v.begin() << "\n";
		}
	}

}