#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
int arr[200002];
pair<int,int>sum[200002];//+개수 -개수

int main() {
	int test; cin >> test;
	while (test--) {
		int a, b; cin >> a >> b;
		cin >> s;
		memset(sum, 0, sizeof(sum));

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+')sum[i + 1].first = sum[i].first + 1;
			else sum[i + 1].second = sum[i].second + 1;

		}
		cout << endl;
		for (int i = 0; i < b; i++) {
			int cnt = 0;
			int l, r; cin >> l >> r;
			int max_f = 0, min_f = 0, max_b = 0, min_b = 0;
			if (l > 1) {
			max_f = MAX[l - 1];
				min_f = MIN[l - 1];
			}
			if (r < a) {
				max_b = MAX[a] - sum[r] + sum[l - 1];
			   min_b = MIN[a] - sum[r] + sum[l - 1];
			}
				int low = min(min_f, min_b);
				int high = max(max_f, max_b);
				cout << "MAX: " << high << " " << "MIN:" << low << " ";
				if (low > 0)cnt++;
				cnt += abs(high - low)+1;
				cout << cnt << "\n";
			}
		}
	
}