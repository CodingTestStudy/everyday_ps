#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int arr[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,-1,1,-1,1, };
bool check[51][51];
void bfs(int st,int ed,int x, int y) {
	queue<pair<int, int>>q;
	q.push({ st,ed });
	check[st][ed] = true;
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= x || ny >= y || nx < 0 || ny < 0)continue;
			if (check[nx][ny])continue;
			if (!arr[nx][ny])continue;
			check[nx][ny] = true;
			q.push({ nx,ny });
		}
		
	}
}
int main() {
	while (1) {
		int a, b; cin >> a >> b;
		if (!a && !b)break;
		for (int i = 0; i < b; i++)for (int j = 0; j < a; j++)check[i][j] = false;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				cin >> arr[i][j];
			}
		}
		int num = 0;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				if (!arr[i][j])continue;
				if (check[i][j])continue;
				bfs(i, j,b,a);
				num++;
			}
		}
		cout << num << "\n";
	}
}