#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int M[130][130];
int n;
string s;
void merge(int ns, int ms, int ne, int me)
{
	int check = M[ns][ms];

	for (int i = ns; i < ne; ++i) {
		for (int j = ms; j < me; ++j) {
			if (check == 0 && M[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && M[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				cout << "(";
				merge(ns, ms, (ns + ne) / 2, (ms + me) / 2);
				merge(ns, (ms + me) / 2, (ns + ne) / 2, me);
				merge((ns + ne) / 2, ms, ne, (ms + me) / 2);
				merge((ns + ne) / 2, (ms + me) / 2, ne, me);
				cout << ")";
				return;
			}
		}
	}

	cout << check;

	return;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < n; ++j)M[i][j] = s[j] - '0';
	}
	merge(0, 0, n, n);
}