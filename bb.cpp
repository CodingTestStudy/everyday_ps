#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string a, b;

int main() {
	int n; cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a.size() < b.size())swap(a, b);
	int T=lcm(a.size(), b.size());
	string temp1 = a;
	string temp2 = b;
	while (temp1.size() < T)temp1 += a;
	while (temp2.size() < T)temp2 += b;
	if (temp1 != temp2)cout << "-1" << "\n";
	else cout << temp1<<"\n";
	}
}