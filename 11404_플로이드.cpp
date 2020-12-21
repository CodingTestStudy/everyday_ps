#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
int dist[101][101];
int n, m;
void floyd_warshall() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j][i] == INF || dist[i][k] == INF)continue;
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		 dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (dist[a][b] < c)continue;
		dist[a][b] = c;
	}
	
	floyd_warshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)cout << "0" << " ";
			else if (dist[i][j] == INF)cout << "0"<<" ";
			else cout << dist[i][j] << " ";
	}
		cout << endl;
	}
}