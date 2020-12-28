#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int arr[100001];

int sol(int st, int en) {
    if (st == en) return arr[st];
    int mid = (st + en) / 2;
    int ret = max(sol(st, mid), sol(mid + 1, en));
    cout << "mid: " << mid << " " << "result :" << ret << endl;
    int lo = mid, hi = mid + 1;
    int height = min(arr[lo], arr[hi]);
    ret = max(ret, height * 2);
    while (lo > st || hi < en) {
        if (lo == st || arr[lo - 1] < arr[hi + 1]) {
            hi++;
            height = min(height, arr[hi]);
        }
        else {
            lo--;
            height = min(height, arr[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    fastio;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << sol(0, n - 1) << '\n';
}