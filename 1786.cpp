#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1000001
using namespace std;
int fail[MAX];
vector<int>ans;
int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);
	int t_size = T.size();
	int p_size = P.size();
	for (int i = 1, j = 0; i < p_size; i++) {
		while (j > 0 && P[i] != P[j])j = fail[j - 1];
		if (P[i] == P[j])fail[i] = ++j;
	}
	for (int i = 0, j = 0; i < t_size; i++) {
		while (j > 0 && T[i] != P[j])j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == p_size - 1) {
				ans.push_back(i - p_size + 2);
				j = fail[j];
			}
			else j++;
		}
	}
	cout << ans.size() << endl;
	for (auto answer : ans)cout << answer << endl;
}