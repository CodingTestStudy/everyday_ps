#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
bool ok;
int color[20001];
void bfs(int st,vector<vector<int>>& v) {
	queue<pair<int, int>>q;
	q.push({ 1,st });
	color[st] = 1;
	while (!q.empty()) {
		auto [cnt, now] = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int nx = v[now][i];
			if (color[nx] == cnt)ok = true;
			if (color[nx])continue;
			color[nx] = 3-cnt;
			q.push({ 3-cnt,nx });
			
		}
	}
}
int main() {
	int test_case; cin >> test_case; f;
	while (test_case--) {
		int node, num; cin >> node >> num;
		vector<vector<int>>v;
		memset(color, false, sizeof(color));
		v.resize(node+1);
		ok = false;
		for (int i = 0; i < num; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= node; i++) {
			if (color[i])continue;
			bfs(i,v);
		}
		if (ok)cout << "NO" << "\n";
		else cout << "YES" << "\n";
		
	}
}