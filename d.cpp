#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 200001
using namespace std;
int num;
priority_queue<long long>q;
int main() {
	int test; cin >> test;
	while (test--) {
		 cin >> num;
		long long cnt1 = 0;
		long long cnt2 = 0;
		for (int i = 0; i < num; i++) {
			long long a; cin >> a;
			q.push(a);
		}
		int cur = 1;
		for (int i = 0; i < num; i++) {
			long long now = q.top();
			q.pop();
			if (cur) {
				if (now % 2 == 0)cnt1 += now;
				cur = 0;
			}
			else {
				if (now % 2)cnt2 += now;
				cur = 1;
			}
		}
		
		if (cnt1 > cnt2)cout << "Alice" << "\n";
		else if (cnt1 < cnt2)cout << "Bob" << "\n";
		else cout << "Tie" << "\n";
	}
}
