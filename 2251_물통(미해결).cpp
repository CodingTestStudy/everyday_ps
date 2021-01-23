#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v;
int n, ans,cur;
int color[3];// 현재 물통 1,2,3
int MAX[3];//물통 최대크기
map<int, int>M;
bool check[201][201][201];
queue<tuple<int, int, int>>q;
void bfs(int cnt) {
	q.push({ 0,0,cnt });

	while (!q.empty()) {
		auto [a, b, c] = q.front();
		q.pop();
		if (check[a][b][c])continue;
		check[a][b][c] = true;
		if (a == 0)M[c]++;
		if (a + b > MAX[1])q.push({ a + b - MAX[1],MAX[1],c });
		else q.push({ 0,a + b,c });
		if (a + c > MAX[2])q.push({ a + c - MAX[2],b,c });
		else q.push({ 0,b,a + c });
		if (b + a > MAX[0])q.push({ MAX[0],a + b - MAX[0],c });
		else q.push({ a + b,0,c });
		if (b + c > MAX[2])q.push({ a,b + c - MAX[2],MAX[2] });
		else q.push({ a,0,b + c });
		if (c + a > MAX[0])q.push({ MAX[0],b,a + c - MAX[0] });
		else q.push({ a + c,b,0 });
		if (c + b > MAX[1])q.push({ a,MAX[1],b + c - MAX[1] });
		else q.push({ a,b + c,0 });
	}
}
int main() {
	cin >> MAX[0] >> MAX[1] >> MAX[2];
	color[2] = MAX[2];
	bfs(color[2]);
	for (auto T : M)cout << T.first << " ";
}