#include <iostream>
#include <algorithm>
#include <string>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main() {
	while (1) {
		string s; cin >> s; f;
		if (stoi(s) == 0)break;
		string temp = s;
		reverse(temp.begin(), temp.end());
		if (s == temp)cout << "yes" << endl;
		else cout << "no" << endl;;
	}
}