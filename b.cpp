#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	int n; f;
	cin >> n;
	while (n--) {
		int two = 0;
		int one = 0;
		int num;	cin >> num;
		for (int i = 0; i < num; i++) {
			int a; cin >> a;
			if (a == 1)one++;
			if (a == 2)two++;
		}
		if (one % 2)cout << "NO" << "\n";
		else if ((one + 2 * two) % 2)cout << "NO" << "\n";
		else if (one == 0 && (two %2)==1)cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}