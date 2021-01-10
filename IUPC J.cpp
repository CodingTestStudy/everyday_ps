#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long n, m,ans;
vector<int>v;
int main() {
	cin >> n;
	long long temp = 1;
	while (n) {
		ans += n % 7 *temp;
		temp *= 3;
		n /= 7;
	}
	
	cout << ans;
}
