#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
bool check[51];
vector < vector<int>>v;
int parent[51];
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y)return;
	if (x > y)swap(x, y);
	parent[y] = x;
	return;
}
int main() {
	cin >> n >> m;
	int a; cin >> a;
	for (int i = 1; i <= 50; i++)parent[i] = i;
		for (int k = 0; k <a ; k++) {
			int t; cin >> t;
			Union(t, 0);
		}
		v.resize(m);
		for (int i = 0; i < m; i++) {
			int num; cin >> num;
			for (int j = 0; j < num; j++) {
				int a; cin >> a;
				v[i].push_back(a);
			}
			int temp = v[i][0];
			for (auto T : v[i])Union(temp, T);
		}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		bool ok = false;
		for (auto T : v[i]) {
			for (int i = 1; i <= n; i++) {
				if (parent[i])continue;
				if (find(T) == find(i)) {
					ok = true;
					break;
				}
			}
		}
		if (!ok)cnt++;
	}
		cout << cnt;
}