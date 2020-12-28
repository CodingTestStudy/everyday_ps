#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
stack<int>st;
int main() {
	int n; cin >> n;
	int sum = 0;
	int cur = -1;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0)st.pop();
		else st.push(a);
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}