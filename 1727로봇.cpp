#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1e9
using namespace std;
int n, m;
int arr[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dist[101][101][4];
int stx, sty, ssd, edx, edy, edd;
queue<tuple<int, int, int, int>>q;//x,y,d,cnt;

void bfs() {
	q.push({ stx,sty,ssd,0 });
	dist[stx][sty][ssd] = 0;
	while (!q.empty()) {
		auto [x, y, d, cnt] = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {//방향
			int k = d;
			int ncnt = cnt;
			if (i == 1) {
				k = (d + 1) % 4;
				ncnt++;
			}
			if (i == 2) {
				k = (d - 1) % 4;
				ncnt++;
			}
			for (int j = 0; j <= 3; j++) {//1~3거리
				int nx = x + dx[k] * j;
				int ny = y + dy[k] * j;
				if (arr[nx][ny] == 1)break;
				if (nx >= n || ny >= m || nx < 0 || ny < 0)break;
				if (dist[nx][ny][k] > ncnt + 1) {
					dist[nx][ny][k] = ncnt + 1;
					q.push({ nx,ny,k,ncnt + 1 });
				}
			}
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> arr[i][j];
		for (int k = 0; k < 4; k++)dist[i][j][k] = INF;
	}
	cin >> stx >> sty >> ssd;
	cin >> edx >> edy >> edd;
	stx--; sty--; ssd--;
	if (ssd == 1)ssd = 2;
	if (ssd == 2)ssd = 1;
	if (edd == 1)edd = 2;
	if (edd == 2)edd = 1;
	edx--; edy--; edd--;// 좌표 설정 
	bfs();
	cout << dist[edx][edy][edd];
}