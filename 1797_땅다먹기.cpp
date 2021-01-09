#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s, s1;
int n, m;
vector<int>v;
vector<int>v1;
int sum[201][201];
int arr[201][201];
int ans = 0;

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++) cin >> arr[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + arr[i][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	int ans = -10000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = n; k >= i; k--) {
				for (int p = m; p >= j; p--) {
					ans = max(sum[k][p] - sum[i-1][p]-sum[k][j-1]+sum[i-1][j-1], ans);
				}
			}
		}
	}
	cout << ans;

}