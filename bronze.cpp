#include <iostream>
#include <vector>

using namespace std;
bool check[10];
int ans;
void dfs(int idx) {
	if (idx == 5) {
		for (int i = 0; i < 5; i++) {
			if (!check[i])continue;
			cout << i << " ";
		}
		cout << endl;
		ans++;
		return;
	}
	dfs(idx + 1);
	check[idx] = true;
	dfs(idx + 1);
	check[idx] = false;
}
int main() {
	dfs(0);
	cout << ans;
}