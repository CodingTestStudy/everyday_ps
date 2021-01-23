#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool check[201][201][30];
int arr[201][201];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { -1,0,0,1 };
int ax[8] = { -2,-1,1,2,2,1,-1,-2 };
int ay[8] = { 1,2,2,1,-1,-2,-2,-1 };
int n, m, k, ans=1e9;
queue<tuple<int, int, int,int>>q;//x,y,cnt,move;
void bfs() {
	q.push({ 0, 0, 0,0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		auto [x, y, cnt,num] = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) {
			ans = num;
			break;
		}
			if (cnt < k) {
				for (int i = 0; i < 8; i++) {
					int nx = x + ax[i];
					int ny = y + ay[i];
					if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
					if (arr[nx][ny] != 0)continue;
					if (check[nx][ny][cnt+1])continue;
					check[nx][ny][cnt+1] = true;
					q.push({ nx,ny,cnt + 1,num+1 });
				}
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
				if (arr[nx][ny] != 0)continue;
				if (check[nx][ny][cnt])continue;
				check[nx][ny][cnt] = true;
				
				q.push({ nx,ny,cnt,num+1 });
			}
		}

}
int main() {
	cin >> k >> n >> m;
	swap(n, m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
	bfs();
	if (ans == 1e9)cout << "-1";
	else cout << ans;
}