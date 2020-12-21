#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
char map[1010][1010];
bool check[1010][1010][2];
vector<tuple<int,int,int>>v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m,k,ans;
queue<tuple<int,int,int,int>>q;
pair<int, int>cur;
bool bfs(pair<int, int>p) {
	q.push({p.first,p.second,0,0});
	check[p.first][p.second][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'F') {
				q.push({ i,j,1,0 });
				check[i][j][1] = true;
			}
		}
	}
	while (!q.empty()) {
		auto [x, y, idx, cnt] = q.front();
		q.pop();
		if (idx == 0 && map[x][y] == 'F')continue;
		if (idx == 0) {
			if (x >= n || x < 0 || y < 0 || y >= m) {
				ans = cnt;
				return true;
			}
		}
		if (idx == 1) if (x >= n || x < 0 || y < 0 || y >= m) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (idx == 0) {
				if (map[nx][ny] == 'F' || map[nx][ny] == '#')continue;
				if (check[nx][ny][0])continue;
				check[nx][ny][0] = true;
				map[nx][ny] = 'J';
				q.push({ nx,ny,0,cnt + 1 });
			}
			else {
				if (map[nx][ny] == '#')continue;
				if (check[nx][ny][1])continue;
				check[nx][ny][1] = true;
				map[nx][ny] = 'F';
				q.push({ nx,ny,1,cnt + 1 });
			}

		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";

			}
			cout << endl;
		}
	}
		return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'J')cur = { i,j };
		}
	}
	if (bfs(cur))cout << ans;
	else cout << "IMPOSSIBLE";
}