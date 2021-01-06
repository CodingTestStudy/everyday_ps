#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
queue<int>p1;
queue<int>p2;
int main() {
	int test; cin >> test;
	while (test--) {
		int num; cin >> num;
		int cnt = 0;
		int cnt1 = 0;
		for (int i = 0; i < num; i++) {
			int k; cin >> k;
			p1.push(k);
		}
		for (int i = 0; i < num; i++) {
			int k; cin >> k;
			p2.push(k);
		}
		int cur = 0;
		int cur1 = 0;
		for (int i = 0; i < num; i++) {
			int x = p1.front();
			int y = p2.front();
			if (cur > 0)x += cur - 1;
			if (cur1 > 0)y += cur1 - 1;
			p1.pop(); p2.pop();
			if (x > y) {
				cur = x - y;
				cur1 = 0;
				cnt++;
			}
			else if (x < y) {
				cur1 = y - x;
				cur = 0;
				cnt1++;
			}
			else {
				cur = 0;
				cur1 = 0;
			}
		}
		if (cnt > cnt1)cout << "1" << "\n";
		else if (cnt < cnt1)cout << "2" << "\n";
		else cout << "0" << "\n";
	}
}