#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<queue>
#include<map>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
int n, k;
int ans = 1e9;
string s;
map<string, int>mp;
queue<pair<string,int >>q;
void bfs(string t,string target) {
	q.push({ t,0 });
	while (!q.empty()) {
		string temp = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (temp == target) {
			ans = cnt;
			break;
		}
		if (!mp.count(temp)) {
			mp[temp] = 1;
			for (int i = 0; i <= temp.size() - k; i++) {
				string T = temp;
				reverse(T.begin() + i, T.begin() + i + k);
				q.push({ T, cnt + 1 });
			}
		}
		

	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		s += to_string(k);
	}	
	string target = s;
	sort(target.begin(), target.end());
	bfs(s,target);
	if (ans == 1e9)cout << "-1";
	else cout << ans;
}