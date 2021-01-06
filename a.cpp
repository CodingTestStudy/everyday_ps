#include <iostream>

using namespace std;
int n;

int main() {
	cin >> n;
	while (n--) {
		int cnt = 1;
		int w = 0;
		int h = 0;
		int a, b, c; cin >> a >> b >> c;
		while (1) {
			if (a % 2 == 0) {
				w++;
				a /= 2;
			}
			else break;
		}
		while (1) {
			if (b % 2 == 0) {
				h++;
				b /= 2;
			}
			else	break;
		}
		cnt <<=( w + h);
		if (cnt >= c)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}