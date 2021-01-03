#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int test, n, m,a,b, target;
int arr[51][51];
bool check[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bfs() {
	queue<pair<int, int>>q;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)continue;
			if (check[i][j])continue;
			q.push({ i,j });
			check[i][j] = true;
			num++;
			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
					if (check[nx][ny])continue;
					if (!arr[nx][ny])continue;
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			
		}
	}
	return num;
}
int main() {
	cin >> test;
	while (test--) {
		cin >> n >> m >> target;
		swap(n, m);
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)arr[i][j] = 0;
		for (; target--;) {
			cin >> a >> b;
			arr[b][a] = 1;
		}
		cout << bfs() << endl;

	}
}