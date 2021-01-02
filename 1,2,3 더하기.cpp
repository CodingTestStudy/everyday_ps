#include <iostream>
#include <vector>
using namespace std;
int dp[20];

void top_down() {

}

int n, m;
int main() {
	cin >> n;
	while (n--) {
		cin >> m;
		cout << dp[n];
	}
}