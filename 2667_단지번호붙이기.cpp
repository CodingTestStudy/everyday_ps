#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
int map[26][26];
bool check[26][26];
vector<int>v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
queue<pair<int,int>>q;
int  bfs(int x, int y,int num) {
	check[x][y] = true;
	map[x][y] = num;
	q.push({ x, y });
	int cnt = 1;
	while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
			if (map[nx][ny] == 0)continue;
			if (check[nx][ny])continue;
			check[nx][ny] = true;
			map[nx][ny] = num;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j]=s[j]-'0';
		}
	}
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				v.push_back(bfs(i, j,num++));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << num - 1 << endl;
	for (auto T : v)cout << T << endl;
	
}