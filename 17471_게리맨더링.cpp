#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
int  n;
int arr[11];
bool color[11];// 빨강은 1 파랑은 0
int ans = 1e9;
bool check[11];
vector<vector<int>>v;
void make_color(int idx, int cnt) {
	if (idx != 0 && (cnt == 0 || cnt == n))return;
	if (idx == n) {
		memset(check, false, sizeof(check));
		int red = 0;
		int blue = 0;
		int idx = -1;
		int idx1 = -1;
		for (int i = 1; i <= n; i++) {
			if (color[i])continue;
			idx = i;
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (!color[i])continue;
			idx1= i;
			break;
		}
		queue<pair<int, int>>q1;
		queue<pair<int, int>>q2;
		q1.push({ 0,idx });//색없는거
		check[idx] = true;
		q2.push({ 1,idx1 });//색있는거
		check[idx1] = true;
		while (!q1.empty()) {
			auto [now_color, now] = q1.front();
			q1.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				if (check[next])continue;
				if (color[next])continue;
				check[next] = true;
				q1.push({ 0,next });
			}
		}
		while (!q2.empty()) {
			auto [now_color, now] = q2.front();
			q2.pop();
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				if (check[next])continue;
				if (!color[next])continue;
				check[next] = true;
				q2.push({ 0,next });
			}
		}
		for (int i = 1; i <= n; i++)if (!check[i])return;
			for (int i = 1; i <= n; i++) {
				if (color[i])red += arr[i];
				else blue += arr[i];
			}
			ans = min(ans, abs(red - blue));
			return;
		}
	for (int i = idx+1; i <= n; i++) {
		color[i] = true;
		make_color(i, cnt + 1);
		color[i] = false;
	}
	}

int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int k;  cin >> k;
			v[i].push_back(k);
		}
	}
	make_color(0,0);
	if (ans == 1e9)cout << "-1";
	else cout << ans;
}