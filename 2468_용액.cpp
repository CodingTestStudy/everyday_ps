#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
int n;
vector<int>v;
pair<int, int>temp;
int ans = 2e9,answer=2e9;
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; i++) {
		int low = i+1;
		int high = v.size()-1;
		int cur = v[i];
		int mid = (low + high) / 2;
		while (low <= high) {
			mid = (low + high) / 2;
			if (cur + v[mid] > 0)high = mid - 1;
			else low = mid + 1;
			if (ans > abs(cur + v[mid])) {
				ans = min(ans, abs(cur + v[mid]));
				temp = { i,mid };
			}
		}
	}
	cout << v[temp.first] << " " << v[temp.second];
}