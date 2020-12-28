#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	ll sum = 0;
	int temp = 31;
	for (int i = 2; i < n; i++) {
		int a = s[i] - 96;
		sum += a*(temp * 31) % 1234567891;
	}
	if (s.size() >= 2)sum += s[0] - 96 + (s[1] - 96) * 31;
	else if (s.size() == 1)sum += s[0] - 96;
	cout << sum;
}