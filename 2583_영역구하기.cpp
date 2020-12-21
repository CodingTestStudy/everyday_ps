#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
int map[101][101];
bool check[101][101];
vector<int>v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m,k;
queue<pair<int, int>>q;
int  bfs(int x, int y, int num) {
	check[x][y] = true;
	q.push({ x, y });
	int cnt = 1;
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
			if (map[nx][ny] == 1)continue;
			if (check[nx][ny])continue;
			check[nx][ny] = true;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n>>m>>k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++) {
			for (int k = a; k <c ; k++) {
				map[j][k] = 1;
			}
		}
	}
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !check[i][j])
				v.push_back(bfs(i,j,num++));
		}
	}
	sort(v.begin(), v.end());
	cout << num - 1 << endl;
	for (auto T : v)cout << T <<" ";

}