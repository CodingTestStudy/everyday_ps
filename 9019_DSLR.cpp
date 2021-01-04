#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll, string> pls;
ll N, M;
string BFS() {
    string ret;
    vector<pls> arr(10005);
    queue<ll> q;
    arr[N].first = 1;
    q.push(N);
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        if (x == M) {
            ret = arr[M].second;
            break;
        }
        ll dir[4] = { (x * 2) % 10000, ((x + 10000) - 1) % 10000, (x % 1000) * 10 + x / 1000, (x % 10) * 1000 + x / 10 };
        char c[4] = { 'D','S','L','R' };
        for (int i = 0; i < 4; i++) {
            if (arr[dir[i]].first == 0) {
                arr[dir[i]].first = 1;
                arr[dir[i]].second = arr[x].second + c[i];
                q.push(dir[i]);
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << BFS() << "\n";
    }
    return 0;
}