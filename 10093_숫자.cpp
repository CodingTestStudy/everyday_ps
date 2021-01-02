#include <iostream>
#include <vector>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int main() {
	fastio;
	 ll a, b; cin >> a >> b;
	 if (a > b)swap(a, b);
	 if (a == b)cout << "0" << endl;
	 else {
		 cout << b - a - 1 << endl;
		 while (a < b - 1) {
			 cout << ++a << " ";
		 }
	 }

}