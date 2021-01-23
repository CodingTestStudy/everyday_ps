#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int>x;
int main() {
	fastio;
	int a, b; cin >> a >> b;
	x.resize(a+b);
	for (int i = 0; i < a + b; i++)cin >> x[i];
	sort(x.begin(), x.end());
	for (auto T : x)cout << T << " ";
}