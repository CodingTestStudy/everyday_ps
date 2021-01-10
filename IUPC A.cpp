#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long dp[201][201];
string s;
map<char, char>M;
int main() {
	cin >> s;
	M['E'] = 'I'; M['I'] = 'E'; M['S'] = 'N'; M['N'] = 'S'; M['T'] = 'F'; M['F'] = 'T';
	M['J'] = 'P'; M['P'] = 'J';
	for (auto T : s)cout << M[T];

}