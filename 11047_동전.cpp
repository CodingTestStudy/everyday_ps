#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v;
int main() {
	int a, b; cin >> a >> b;
	v.resize(a);
	for (int i = 0; i < a; i++)cin >> v[i];
		int cnt = 0;
		for (int i = a - 1; i >= 0; i--) {
			int temp = b;
			cnt += temp / v[i];
			b = temp % v[i];
	}
		cout << cnt;

}