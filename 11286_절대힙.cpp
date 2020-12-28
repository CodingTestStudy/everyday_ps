#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
struct cmp {
	bool operator() (pair<int, int>a, pair< int, int>b) {
		auto [a1, b1] = a;
		auto [a2, b2] = b;
		if (a1 == a2)return b1 > b2;
		return a1 > a2;
	}
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
int main() {
	int n; cin >> n; f;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) {
			if (q.empty())cout << "0" << "\n";
			else {
				auto [a1, b1] = q.top();
				q.pop();
				cout << b1 << "\n";
			}
		}
		else q.push({ abs(a),a });
	}
}