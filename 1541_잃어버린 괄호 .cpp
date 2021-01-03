#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string s;
vector<int>v;
int main() {
	cin >> s;
	int index =s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			index = i;
			break;

		}
	}
		string T = "";
		int sum = 0;
		for (int i = 0; i < index; i++) {
			if (s[i] >= 48 && s[i] <= 57)T += s[i];
			else {
				sum += stoi(T);
				T.clear();
			}
		}
		sum += stoi(T);
		T.clear();
		for (int i = index + 1; i < s.size(); i++) {
			if (s[i] >= 48 && s[i] <= 57)T += s[i];
			else {
				sum -= stoi(T);
				T.clear();
			}
			
		}
		sum -= stoi(T);
		cout << sum;
}