#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<tuple<int, int, int>>robot;
int arr[101][101];
int n, m,idx;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool flag;
bool test(int num, char k, int T) {
	auto[a,b,c] = robot[num-1];
	int prev_x = a;
	int prev_y = b;
	for (int i = 0; i < T; i++) {
		if (k == 'L') {
			c--;
			if (c < 0)c = 3;
		}
		else if (k == 'R')c = (c + 1) % 4;
		else {
			a += dx[c];
			b += dy[c];
		}
		if (a > n || b > m || a <= 0 || b <= 0) return false;
		if (arr[a][b] != 0 && arr[a][b] != num) {
			flag = true;
			idx = arr[a][b];
			return false;
		}
		arr[prev_x][prev_y] = 0;
		arr[a][b] = num;
		prev_x = a; prev_y = b;
		robot[num - 1] = { a,b,c };
	}
	return true;
}
int main() {
		cin >> n >> m;
		swap(n, m);
		int num, order; cin >> num >> order;
		int cnt = 1;
		for (int i = 0; i < num; i++) {
			int a, b; char c; cin >> a >> b >> c;
			swap(a, b);
			a = n - a + 1;
			arr[a][b] = cnt++;
			if (c == 'E')robot.push_back({ a,b,0 });
			else if (c == 'S')robot.push_back({ a,b,1 });
			else if (c == 'W')robot.push_back({ a,b,2 });
			else robot.push_back({ a,b,3 });

		}
		for (int i = 0; i < order; i++) {
			int num; char k; int T; cin >> num >> k >> T;
			if (!test(num, k, T)) {
				if (!flag)cout << "Robot " << num << " crashes into the wall";
				else cout << "Robot " << num << " crashes into robot " << idx;
				return 0;

			}
		}
		cout << "OK" << endl;
}