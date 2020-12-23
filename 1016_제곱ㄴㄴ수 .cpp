#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
bool check[1000001];
long long MIN, MAX;
int main() {
	cin >> MIN >> MAX;
	for (ll i = 2; i * i <=MAX; i++) {
		ll k = i * i;
		if(MIN%k!=0)for (ll j = MIN+k-(MIN%k); j <= MAX; j += k) {
			check[j - MIN] = true;
		}
		else {
			for (ll j = MIN; j <= MAX; j += k) {
				check[j - MIN] = true;
			}
		}
	}
	int cnt = 0;
	for (ll i = MIN; i <= MAX; i++) {
		if (!check[i - MIN])cnt++;
	}
	cout << cnt;
}