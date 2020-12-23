#include <string>
#include<algorithm>
#include<queue>
#include<map>
#include <iostream>
#include <stack>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
string s;
stack<char>st;
string dfs(string T) {
	cout << T << endl;
	string cur = "";
	for (int i = 0; i < T.size(); i++) {
		if (T[i] == '(') {
			st.push(T[i]);
			dfs(T.substr(i+1, 50));
		}
		if (T[i] == ')') {
			while (st.top() != '(')st.pop();
			st.pop();
			int temp = st.top()-'0';
			temp--;
			st.pop();
			while (temp--) {
				cur += cur;
			}
			while (st.top() != '(') {
				char pp = st.top();
				st.pop();
				cur.insert(0, 1, pp);
			}
			if (st.top() == '(')st.pop();
			return cur+T.substr(i+1,50);
		}
		cur += T[i];
		st.push(T[i]);
	}
	while (!st.empty()) {
		char P = st.top();
		st.pop();
		T.insert(0,1,P);
	}
}
int main() {

	cin >> s;
	cout<<dfs(s).size();
}