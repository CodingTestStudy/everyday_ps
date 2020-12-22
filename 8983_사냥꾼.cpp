#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
int n, m, k;
vector<int>v;
vector<pair<int, int>>animal;
bool check;
int main() {
	cin >> n >> m >> k; f;
	v.reserve(100000);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (; m--;) {
		int a, b; cin >> a >> b;
		animal.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	sort(animal.begin(), animal.end());
	int cnt = 0;
	for (int i = 0; i < animal.size(); i++) {
		auto [a, b] = animal[i];
		check = false;
		int index = lower_bound(v.begin(), v.end(), a) - v.begin();
		if (index == v.size()) {
			if (a - v[index - 1] + b <= k)cnt++;
			continue;
		}
		if (v[index] - a + b <= k)check = true;
		if(index!=v.size()-1)if (v[index + 1] - a + b <= k)check = true;
		if(index!=0)if (a - v[index - 1] + b <= k)check = true;
		if (check)cnt++;
		
	}
	cout << cnt;
}