#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
int map[201][201];
int n, m;
int parent[201];
vector<int>v;
bool check;
int find(int x) {
	if (parent[x] == x)return x;
	else return x= find(parent[x]);
}
void Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b)return;
	if (a > b)swap(a, b);
	else parent[b] = a;
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)Union(i, j);
		}
	}
	for (; m--;) {
		int a; cin >> a;
		v.push_back(a);
	}
	int cur = parent[v[0]];
	for (int i = 1; i < v.size(); i++)if (cur != parent[v[i]])check = true;
	if (check)cout << "NO";
	else cout << "YES";

	
}