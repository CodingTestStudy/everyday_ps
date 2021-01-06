#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<pair<char, char>>v;
void dfs(int now,int idx) {
	auto [a, b] = v[now];
	char T = now + 65;
	if(idx==0)cout << T;
	if(a!=-1)dfs(a,idx);
	if (idx == 1)cout << T;
	if(b!=-1)dfs(b,idx);
	if (idx == 2)cout << T;
	return;
}
int main() {
	int n; cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		char a, b, c; cin >> a >> b >> c;
		if (b < 65 || 90 < b)b = -1;
		else b -= 65;
		if (c < 65 || 90 < c)c = -1;
		else c -= 65;
		v[a - 65] = { b,c };
	}
	for (int i = 0; i < 3; i++) {
		dfs(0,i);
		cout << endl;
	}
}