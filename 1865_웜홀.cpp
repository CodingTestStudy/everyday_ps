#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1e9
using namespace std;

int test, n, m;
vector<tuple<int,int, int>>v;

int dist[501];
bool bellman() {
	dist[1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v.size(); j++) {
			auto [now,next, cost] = v[j];
			if (dist[next] > dist[now] + cost)dist[next] = dist[now] + cost;
		}
	}
	for (auto T : v) {
		auto [now,next,cost] = T;
		if (dist[next] > dist[now] + cost)return false;
	}
	return true;
}
int main() {
	cin >> test;
	while (test--) {
		v.clear();
		fill(dist, dist + 501, INF);
		int t;	cin >> n >> m >> t;
		v.resize(n + 1);
		for (int i = 0; i < m + t; i++) {
			int a, b, c; cin >> a >> b >> c;
			if (i < m) {
				v.push_back({ a, b,c });
				v.push_back({ b, a,c });
			}
			else {
				v.push_back({ a, b,-c });
			}
		}
		if (!bellman())cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}