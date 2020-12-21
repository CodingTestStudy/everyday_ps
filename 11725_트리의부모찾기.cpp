#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
int n;
int parent[100001];
vector<vector<int>>v;
queue<int>q;
bool check[100001];
void bfs() {
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (check[nx])continue;
			check[nx] = true;
			parent[nx] = x;
			q.push(nx);
		}
	}
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
		v[a].push_back(b);
	}
	bfs();
	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";
}