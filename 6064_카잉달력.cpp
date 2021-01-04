#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	cin >> n;
	while (n--) {
		int M, N, a, b; cin >> M >> N >> a >> b; f;
		if (a > M || b > N) {
			cout << "-1" << endl;
			continue;
		}
		int MAX = lcm(M, N);
		while (1) {
			if (a > MAX || (a- 1) % N + 1 == b)break;
			a += M;
		}
		if (a>MAX )cout << "-1" << "\n";
		else cout << a << "\n";
	}

}