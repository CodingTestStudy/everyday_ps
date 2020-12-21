#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
ll dist[501];
int n, m;
vector <tuple<int,int, ll>>v;
bool bellman_ford() {
	dist[1] = 0;
	for (int i = 0; i <=n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			auto [a, b, c] = v[j];
			if (dist[a] == INF)continue;
			if (dist[b] > dist[a] + c)dist[b] = dist[a] + c;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		auto [a, b, c] = v[i];
		if (dist[a] == INF)continue;
		if (dist[b] > dist[a] + c)return false;
	}
	return true;

}
int main() {
	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	if (bellman_ford()) {
		for (int i = 2; i <= n; i++) {
			if (dist[i] != INF)cout << dist[i] << "\n";
			else cout << "-1" << "\n";
		}
	}
	else cout << "-1";
}