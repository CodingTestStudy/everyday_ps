#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef	long long ll;
using namespace std;
int n,M;
vector<ll>ans;
vector<pair<ll, ll>>v;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	ll prev = 0;
	ll MAX = 1e18;
	for (auto T : v) {
		auto [a, b] = T;
		if (a > 0)if (prev + a != b) {
			cout << "-1";
			return 0;
		}
		else {
				ll charge = b - a - prev;
				if (prev + a >= 0)if (charge) {
					cout << "-1";
					return 0;
				}
			
			else {
					if (charge <= 0) {
						cout << "-1";
						return 0;
				}
					M = gcd(charge, M);
					if (b && b < MAX)MAX = b;
					if(MAX!=)

			}
		}
	}
	sort(ans.begin(), ans.end());
	ll temp = ans[0];
	bool ok = false;
	
}