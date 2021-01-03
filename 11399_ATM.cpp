#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>v;
int main() {
	int a; cin >> a;
	v.resize(a);
	for (int i = 0; i < a; i++)cin >> v[i];
	sort(v.begin(), v.end());
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		ans += sum;
	}
	cout << ans;

}