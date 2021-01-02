#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
vector<string>v;
bool ok;
bool check[101];
void dfs(string st, int cnt) {

	if (cnt== n) {
		ok = true;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		string temp = v[i];
		if (check[i])continue;
		if (v[i].front() != st.front())continue;
			check[i] = true;
			dfs(temp, cnt+1);
		}
	
}
int main() {
	cin >> n; f;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	check[0] = true;
	dfs(v[0],1);
	if (ok)cout << "1";
	else cout << "0";
}