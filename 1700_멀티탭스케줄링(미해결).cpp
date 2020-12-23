#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<map>;
typedef long long ll;
using namespace std;
int n, k;
vector<int>v;
vector<int>cur;
map<int, int>M;
int arr[101];
int main() {
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < k; i++)cin >> v[k];
	for (int i = 0; i < v.size(); i++) {
		if (M.size() < n) {
			M[v[i]]++;
			continue;
		}
		if(M.count(v[i]))continue;
		int MAX = 0;
		for (auto T : M)cur.push_back(T.first);
		for (int k = 0; k < cur.size(); k++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (cur[k] == v[j]) {
					arr[cur[k]] = j;
					MAX = max(MAX, j);
				}
			}
		}
		int idx = -1;
		for (int i = 1; i <= k; i++) {
			if (arr[i] == MAX)idx = i;

	}
		M.erase(idx);
		
	}
}