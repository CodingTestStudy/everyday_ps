#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int n;
bool check(int num) {
	int mid = (s.size()+num) / 2;
	for (int i = num; i < mid; i++) {
		if (s[i] == s[s.size() - 1+num - i])continue;
		else return false;
	}
	return true;
}
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (!check(i))continue;
		cout << s.size() + i;
		return 0;
	}
}