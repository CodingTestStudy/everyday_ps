#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, int>M;
vector<tuple<int,int,int>>v;
bool cmp(tuple<int, int, int>a, tuple<int, int, int>b) {
	auto [z, x, c] = a; auto [q, w, e] = b;
	if (c == e)return z < q;
	return c > e;
	
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (M[a] == 0) {
			v.push_back({ i,a,1});
			M[a]++;
		}
		else {
			for (int j = 0; j < v.size(); j++) {
				auto [aa, b, c] = v[j];
				if (b == a)v[j] = { aa,b,c + 1 };
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (auto T : v) {
		auto [a, b, c] = T;
		for (int i = 0; i < c; i++) {
			cout << b << " ";
		}
	}
}