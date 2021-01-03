#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n,s,ans;
vector<int>v;
map<int, int>M;
void Left(int idx, int sum) {
	if (idx == n / 2) {
		M[sum]++;
		return;
	}

	Left(idx + 1, sum);
	Left(idx + 1, sum + v[idx]);
}
void Right(int idx, int sum) {
	if (idx == n) {
		ans += M[s - sum];
		return;
	}
	Right(idx + 1, sum);
	Right(idx + 1, sum + v[idx]);
}
int main() {
	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	Left(0, 0);
	Right(n / 2, 0);
}

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