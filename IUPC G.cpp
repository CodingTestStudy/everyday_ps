#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int>v;
int money;
int BNP[14];
int TIMING[14];
int main() {
	cin >> money;
	for (int i = 0; i < 14; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int cnt1 = money;
	int cnt2 = money;
	for (int i = 0; i < 14; i++) {
		int buy = cnt1 / v[i];
		cnt1 -= buy * v[i];
		BNP[i] += buy;
	}
	for (int i = 0; i < 14; i++) {
		cnt1 += v[13] * BNP[i];
	}
	for (int i = 3; i < 14; i++) {
		int prev = 0;
		if (v[i - 3] > v[i - 2])prev = -1;
		else if (v[i - 3] < v[i - 2])prev = 1;
		int up = 0;
		int down = 0;
		int cur = v[i - 2];
		for (int j = i - 1; j <= i; j++) {
			if (cur < v[j]) {
				up++;
				cur = v[j];
			}
			else if (cur > v[j]) {
				down++;
				cur = v[j];
			}
		}
		if (prev == 1&& up==2) {
			for (int k = 0; k < i; k++) {
				cnt2 += v[i] * TIMING[k];
				TIMING[k] = 0;
			}
		}
		else if (prev == -1 && down == 2) {
			int buy = cnt2 / v[i];
			cnt2 -= buy * v[i];
			TIMING[i] += buy;
		}
	}
	for (int i = 0; i < 14; i++) {
		cnt2 += TIMING[i] * v[13];
	}
	if (cnt1 > cnt2)cout << "BNP";
	else if (cnt1 < cnt2)cout << "TIMING";
	else cout << "SAMESAME";
}