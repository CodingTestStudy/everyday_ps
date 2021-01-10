#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	cout << min(min(n / 2, m), (n + m - k) / 3);
}