#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool check[2001][2001];
int n;
queue<tuple<int,int,int>>q;//현재 개수 , 시간
int sol(int target) {
	q.push({ 1,0,0 });
	while (!q.empty()) {
		auto [cnt,board, now] = q.front();
		q.pop();
		if (cnt <= 0)continue;
		if (cnt > 1000)continue;
		if (cnt == target) {
			return now;
			break;
		}
		if (!check[cnt - 1][board]&& cnt>=1) {
			check[cnt - 1][board] = true;
			q.push({ cnt - 1,board,now + 1 });
		}
		if (!check[cnt + board][board]) {
			check[cnt + board][board] = true;
			q.push({ cnt + board,board,now + 1 });
		}
		if (!check[cnt][cnt]) {
			check[cnt][cnt] = true;
			q.push({ cnt,cnt,now + 1 });
		}
	}
	return -1;
}
int main() {
	cin >> n;
	cout << sol(n);
}