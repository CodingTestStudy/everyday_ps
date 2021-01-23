#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int a, b, c;

int main() {
	cin >> a >> b >> c;
	int x = 1, y = 1, z = 1;
	int cur = 1;
	while (1) {
		if (x == a && b == y && c == z) {
			cout << cur;
			break;
		}
		x = (x + 1) % 16;
		if (x == 0)x =1;
		y = (y + 1) % 29;
		if (y == 0)y = 1;
		z = (z + 1) % 20;
		if (z == 0)z = 1;
		cur++;
	}
}