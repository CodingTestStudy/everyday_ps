#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int>v;
int main() {
	int n, num; string s; cin >> n >> num >> s;
	int P = n * 2 + 1;
	int cnt = 1;
	char cur = 'I';
	int idx = s.size();
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'I') {
			idx = i;
			break;
		}
	}
	for (int i = idx+1; i < s.size(); i++) {
		if (s[i] != cur) {
			cnt++;
			cur = s[i];
		}
		else {
			if(cnt)v.push_back(cnt);
			cnt = 0;
			if (s[i] == 'I') {
				cnt = 1;
				cur = 'I';
			}
			else {
				cnt = 0;
				cur = 'O';
			}
		}
	}
	v.push_back(cnt);
	int ans = 0;
	for (auto T : v) {
		if (T >= P)ans += (T - P) / 2 + 1;
	}
	cout << ans;
}