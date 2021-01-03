#include <iostream>	
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n;
unordered_map<int, int>M;
int main() {
	cin >> n; f;
	for (int i = 0; i < n; i++) {
		string s; int a; cin >> s;
		if (s == "add") {
			cin >> a;
			if (M[a])continue;
			M[a]++;
		}
		else if (s == "check") {
			cin >> a;
			if (M[a])cout << "1" << "\n";
			else cout << "0" << "\n";
			
		}
		else if (s == "toggle") {
			cin >> a;
			if (M[a]==1)M[a]--;
			else M[a]++;
		}
		else if (s == "empty") {
			M.clear();
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				if (M[i])continue;
				else M[i]++;
			}
		}
		else if (s == "remove") {
			cin >> a;
			if (M[a]==0)continue;
			M[a]--;
		}
		
	}

}