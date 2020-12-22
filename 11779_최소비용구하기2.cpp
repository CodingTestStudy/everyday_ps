#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
#define INF 999999999999
#define NIL -1
priority_queue< pair<int, int>>q;
vector<vector<pair<int, int>>>v;
ll dist[1001];
int path[1001];
int n, m;
vector<int>R;
vector<pair<ll, string>>answer;
bool cmp(pair<ll, string> a, pair<ll, string>  b) {
	return a.first < b.first;
}
void diac(int st, int ed) {
	q.push({ 0,st });
	dist[st] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		ll cost = -q.top().first;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			ll ncost = v[x][i].second;
			if (dist[nx] > dist[x] + ncost) {
				dist[nx] = dist[x] + ncost;
				path[nx] = x;
				q.push({ -dist[nx],nx });
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	fill(dist, dist + n + 1, INF);
	int start, end;
	cin >> start >> end;
	diac(start, end);
	cout << dist[end] << endl;
	int back = end;
	while (back) {
		R.push_back(back);
		back = path[back];
	}
	cout << R.size() << endl;
	reverse(R.begin(), R.end());
	for (auto t : R)cout << t << " ";
}